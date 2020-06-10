#include "admincontroller.h"
#include "ui_admincontroller.h"
#include<QDebug>
#include<QMessageBox>

/*主界面:空调管理员AirconController
 * @author:张子鸣
 * 后台人机交互界面，设置参数、实时监控、订房/退房、打印账单/详单
 * 负责管理ScheduleObject
 * 接收ScheduleObject发来的信号，对表格信息进行更新
 * *******************************************************/
//构造函数
AdminController::AdminController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置定时器
    sTimer = new QTimer(this);
    sTimer->stop();
    sTimer->setInterval(1000);//设定时间周期为1秒

    //系统参数初始化
    SystemStatus = false;
    FeeRate[Low] = static_cast<float>(ui->LFeeSpin->value());
    FeeRate[Middle] = static_cast<float>(ui->MFeeSpin->value());
    FeeRate[High] = static_cast<float>(ui->HFeeSpin->value());
    TempLimit.Highest = ui->HighestTempSpin->value();
    TempLimit.Lowest = ui->LowestTempSpin->value();

    //界面初始化
    SystemStatusLabel = new QLabel("系统状态: 关机", this);
    SystemStatusLabel->setMinimumWidth(250);
    CurrentServeNumLabel = new QLabel("当前入住数: 0", this);
    CurrentServeNumLabel->setMinimumWidth(200);
    SystemRunTimeLabel = new QLabel("系统运行时间: ", this);
    SystemRunTimeLabel->setMinimumWidth(200);
    ui->statusBar->addWidget(SystemStatusLabel);
    ui->statusBar->addWidget(CurrentServeNumLabel);
    ui->statusBar->addWidget(SystemRunTimeLabel);

    connect(sTimer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));//定时器超时信号绑定
}
//析构函数
AdminController::~AdminController()
{
    delete sTimer;
    delete SystemStatusLabel;
    delete CurrentServeNumLabel;
    delete ui;
}

//定时器超时槽函数
void AdminController::on_timer_timeout()
{
    QTime curTime = QTime::currentTime();
    int sDuration = sTimeCounter.elapsed()/1000;//系统运行时间，单位：秒
    SystemRunTimeLabel->setText(QString::asprintf("系统运行时间: %d分%d秒", sDuration/60, sDuration%60));//设置状态栏时间
    //设置LCD
    ui->HourLcd->display(curTime.hour());
    ui->MinuteLcd->display(curTime.minute());
    ui->SecondLcd->display(curTime.second());
}

//开机槽函数
void AdminController::on_TurnOnButton_clicked()
{
    if(SystemStatus)
        return;
    SystemMode = ui->ModeCold->isChecked();//1COLD 0HOT
    //启动时间显示
    sTimeCounter.start();//启动计时器
    sTimer->start();//启动定时器
    QTime curTime = QTime::currentTime();
    ui->HourLcd->display(curTime.hour());
    ui->MinuteLcd->display(curTime.minute());
    ui->SecondLcd->display(curTime.second());

    SystemStatus = ui->ModeCold->isChecked();
    SystemStatusLabel->setText("系统状态: 开机");
#ifdef _DEBUG
    qDebug()<<"模式:"<<SystemMode<<(SystemMode?"COLD":"HOT");
#endif

    scheduler = new ScheduleObject(TempLimit, &SystemMode, FeeRate);//创建调度对象

    connect(scheduler, SIGNAL(ServerObjectStart(int, QTime)), this, SLOT(Table_NewServerObjectCreated(int, QTime)));
    connect(scheduler, SIGNAL(ServerObjectPause(int)), this, SLOT(Table_ServerObjectPaused(int)));
    connect(scheduler, SIGNAL(ServerObjectResume(int)), this, SLOT(Table_ServerObjectResumed(int)));
    connect(scheduler, SIGNAL(Refresh_Signal(int, int, int, int, int, float)),
            this, SLOT(Table_ServerObjectRefreshed(int, int, int, int, int, float)));

#ifdef _DEBUG
    for(int i = 3; i > 0; --i)
    {
        //scheduler->createServerObject(600 + i);
    }
#endif
}
//关机槽函数
void AdminController::on_TurnOffButton_clicked()
{
    if(!SystemStatus)
        return;
    //关闭时间显示
    SystemRunTimeLabel->setText("系统运行时间: ");//设置状态栏时间
    sTimer->stop();
    ui->HourLcd->display("0");
    ui->MinuteLcd->display("0");
    ui->SecondLcd->display("0");

    delete scheduler;
    SystemStatus = false;
    SystemStatusLabel->setText("系统状态: 关机");
}

//在界面修改低风速费率
void AdminController::on_LFeeSpin_valueChanged(double LowSpeedFeeRate)
{
    if(LowSpeedFeeRate >= 0 && LowSpeedFeeRate <= FEERATE_UPPER)
    {
        FeeRate[Low] = static_cast<float>(LowSpeedFeeRate);
    }
    else
    {
        //修改非法，修改为最大值
        ui->LFeeSpin->setValue(FEERATE_UPPER);
        FeeRate[Low] = FEERATE_UPPER;
    }
#ifdef _DEBUG
    qDebug()<<QString::asprintf("当前费率：L%f, M%f, H%f",FeeRate[Low], FeeRate[Middle], FeeRate[High]);
#endif
}
//在界面修改中风速费率
void AdminController::on_MFeeSpin_valueChanged(double MiddleSpeedFeeRate)
{
    if(MiddleSpeedFeeRate >= 0 && MiddleSpeedFeeRate <= FEERATE_UPPER)
    {
        FeeRate[Middle] = static_cast<float>(MiddleSpeedFeeRate);
    }
    else
    {
        //修改非法，修改为最大值
        ui->MFeeSpin->setValue(FEERATE_UPPER);
        FeeRate[Middle] = FEERATE_UPPER;
    }
#ifdef _DEBUG
    qDebug()<<QString::asprintf("当前费率：L%f, M%f, H%f",FeeRate[Low], FeeRate[Middle], FeeRate[High]);
#endif
}
//在界面修改高风速费率
void AdminController::on_HFeeSpin_valueChanged(double HighSpeedFeeRate)
{
    if(HighSpeedFeeRate >= 0 && HighSpeedFeeRate <= FEERATE_UPPER)
    {
        FeeRate[High] = static_cast<float>(HighSpeedFeeRate);
    }
    else
    {
        //修改非法，修改为最大值
        ui->HFeeSpin->setValue(FEERATE_UPPER);
        FeeRate[High] = FEERATE_UPPER;
    }
#ifdef _DEBUG
    qDebug()<<QString::asprintf("当前费率：L%.2f, M%.2f, H%.2f",FeeRate[Low], FeeRate[Middle], FeeRate[High]);
#endif
}
//在界面修改最高温度
void AdminController::on_HighestTempSpin_valueChanged(int HighTemp)
{
    if(HighTemp >= TEMP_LOWER && HighTemp <= TEMP_UPPER)
    {
        TempLimit.Highest = HighTemp;
    }
    else
    {
        //修改非法，修改为最大值
        if(HighTemp < TEMP_LOWER)
        {
            ui->HighestTempSpin->setValue(TEMP_LOWER);
            TempLimit.Highest = TEMP_LOWER;
        }
        else if(HighTemp > TEMP_UPPER)
        {
            ui->HighestTempSpin->setValue(TEMP_UPPER);
            TempLimit.Highest = TEMP_UPPER;
        }

    }
#ifdef _DEBUG
    qDebug()<<"修改最高温度"<<QString::asprintf("温度限制：L%d, H%d", TempLimit.Lowest, TempLimit.Highest);
#endif
}
//在界面修改最低温度
void AdminController::on_LowestTempSpin_valueChanged(int LowTemp)
{
    if(LowTemp >= TEMP_LOWER && LowTemp <= TEMP_UPPER)
    {
        TempLimit.Lowest = LowTemp;
    }
    else
    {
        //修改非法，修改为最小值
        if(LowTemp < TEMP_LOWER)
        {
            ui->LowestTempSpin->setValue(TEMP_LOWER);
            TempLimit.Lowest = TEMP_LOWER;
        }
        else if(LowTemp > TEMP_UPPER)
        {
            ui->LowestTempSpin->setValue(TEMP_UPPER);
            TempLimit.Lowest = TEMP_UPPER;
        }
    }
    scheduler->setTempLimit(TempLimit);
#ifdef _DEBUG
    qDebug()<<"修改最低温度"<<QString::asprintf("温度限制：L%d, H%d", TempLimit.Lowest, TempLimit.Highest);
#endif
}

//入住
void AdminController::on_action_checkin_triggered()
{
    if(!SystemStatus)
    {
        QMessageBox::warning(this, "提示", "系统尚未开机");
        return;
    }
    DialogCheckIn *dialog = new DialogCheckIn(this);
    Qt::WindowFlags flags = dialog->windowFlags();
    dialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);

    int ret = dialog->exec();
    if(ret == QDialog::Accepted)
    {
        int RoomId = dialog->getCheckInRoomId();
        if(findRoomIdRow(RoomId) == -1)
        {
            scheduler->createServerObject(RoomId);
            QString label = "房间入住数: ";
            label.append(QString::number(scheduler->countServerObject()));
            CurrentServeNumLabel->setText(label);
            QMessageBox::information(this, "提示", "祝您入住愉快");
        }
        else
        {
            QMessageBox::warning(this, "提示", "该房间已被预订");
        }
        delete dialog;
    }
}
//退房
void AdminController::on_action_checkout_triggered()
{
    if(!SystemStatus)
    {
        QMessageBox::warning(this, "提示", "系统尚未开机");
        return;
    }
    DialogCheckIn *dialog = new DialogCheckIn(this);
    Qt::WindowFlags flags = dialog->windowFlags();
    dialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);

    int ret = dialog->exec();
    if(ret == QDialog::Accepted)
    {
        int RoomId = dialog->getCheckInRoomId();
        int Row = findRoomIdRow(RoomId);
        if(Row == -1)
        {
            QMessageBox::warning(this, "提示", "该房间没有顾客");
        }
        else
        {
            scheduler->destroyServerObject(RoomId);
            Table_ServerObjectDestroyed(RoomId);
            QString payment = ui->tableRoomState->item(Row, FEE)->text();
            payment.prepend("应付空调费: ");
            payment.append("元");
            QMessageBox::information(this, "账单", payment);
        }

        QString label = "房间入住数: ";
        label.append(QString::number(scheduler->countServerObject()));
        CurrentServeNumLabel->setText(label);

        delete dialog;
    }
}

//创建
void AdminController::Table_NewServerObjectCreated(int RoomId, QTime StartTime)
{
    //新建一行
    int rowNum = ui->tableRoomState->rowCount();
    ui->tableRoomState->insertRow(rowNum);

    QString tempStr;//单元格显示内容
    //设置订单编号
    tempStr = QString::asprintf("%d", RoomId);//生成订单编号
    setCenterTableItem(rowNum, NUM, tempStr.append(StartTime.toString("hhmmss")), NUM);
    //设置房间编号
    setCenterTableItem(rowNum, ROOMID, QString::number(RoomId, 10), ROOMID);
    //设置开始时间
    setCenterTableItem(rowNum, STARTTIME, StartTime.toString("hh:mm:ss"), STARTTIME);
    //设置服务对象状态
    setCenterTableItem(rowNum, FEE, "0", FEE);
    setCenterTableItem(rowNum, DURATION, "0", DURATION);
    setCenterTableItem(rowNum, TARGETTEMP, "-", TARGETTEMP);
    setCenterTableItem(rowNum, FANSPEED, "-", FANSPEED);
    setCenterTableItem(rowNum, CURTEMP, "-", CURTEMP);
    setCenterTableItem(rowNum, STATUS, "待机中", STATUS);

#ifdef _DEBUG
    qDebug()<<"成功新建行"<<ui->tableRoomState->rowCount();
#endif
}
//刷新
void AdminController::Table_ServerObjectRefreshed
(int RoomId, int Duration, int TargetTemp, int FanSpeed, int CurrentTemp, float Fee)
{
    int rowNum;
    QTableWidgetItem *RoomIdItem, *StatusItem;
    //找到房间号为RoomId的行
    for(rowNum = 0; rowNum < ui->tableRoomState->rowCount(); rowNum++)
    {
        RoomIdItem = ui->tableRoomState->item(rowNum, ROOMID);
        if(RoomIdItem->text().toInt() == RoomId)
        {
            StatusItem = ui->tableRoomState->item(rowNum, STATUS);
            if(StatusItem->text().compare(QStringLiteral("已退房")) == 0) continue;
            //else if:客户未退房
            setCenterTableItem(rowNum, DURATION, QString::number(Duration, 10).append("s"), DURATION);//修改Duration
            setCenterTableItem(rowNum, TARGETTEMP, QString::number(TargetTemp, 10), TARGETTEMP);//修改TargetTemp
            setCenterTableItem(rowNum, FANSPEED, QString::number(FanSpeed, 10), FANSPEED);//修改FanSpeed
            setCenterTableItem(rowNum, CURTEMP, QString::number(CurrentTemp, 10), CURTEMP);//修改CurrentTemp
            setCenterTableItem(rowNum, FEE, QString::asprintf("%.2f", Fee), FEE);//修改Fee
        }
    }
}
//等待中
void AdminController::Table_ServerObjectPaused(int RoomId)
{
    setRoomStatusItem(RoomId, "等待中");
}
//待机中
void AdminController::Table_ServerObjectStopped(int RoomId)
{
    int rowNum = findRoomIdRow(RoomId);
    setCenterTableItem(rowNum, STATUS, "待机中", STATUS);
    setCenterTableItem(rowNum, TARGETTEMP, "-", TARGETTEMP);
    setCenterTableItem(rowNum, FANSPEED, "-", FANSPEED);
    setCenterTableItem(rowNum, CURTEMP, "-", CURTEMP);
}
//服务中
void AdminController::Table_ServerObjectResumed(int RoomId)
{
    setRoomStatusItem(RoomId, "服务中");
}
//已退房
void AdminController::Table_ServerObjectDestroyed(int RoomId)
{
    int rowNum = findRoomIdRow(RoomId);
    setCenterTableItem(rowNum, STATUS, "已退房", STATUS);
}

void AdminController::on_ModeCold_toggled(bool checked)
{
    SystemMode = checked;
#ifdef _DEBUG
    qDebug()<<"模式:"<<SystemMode<<(SystemMode?"COLD":"HOT");
#endif
}

//根据RoomId找行号
int AdminController::findRoomIdRow(int RoomId)
{
    int rowNum;
    QTableWidgetItem *RoomIdItem, *StatusItem;
    //找到房间号为RoomId的行,已退房的不计算
    for(rowNum = 0; rowNum < ui->tableRoomState->rowCount(); rowNum++)
    {
        RoomIdItem = ui->tableRoomState->item(rowNum, ROOMID);
        if(RoomIdItem->text().toInt() == RoomId)
        {
            StatusItem = ui->tableRoomState->item(rowNum, STATUS);
            if(StatusItem->text().compare(tr("已退房")) == 0)
                continue;

            qDebug()<<rowNum<<"result"<<QString::compare(StatusItem->text(), tr("已退房"));
            return rowNum;//返回找到的行数
        }
    }
    return -1;
}
//修改服务对象状态
void AdminController::setRoomStatusItem(int RoomId, QString text)
{
    int rowNum;
    QTableWidgetItem *RoomIdItem, *StatusItem;
    //找到房间号为RoomId的行
    for(rowNum = 0; rowNum < ui->tableRoomState->rowCount(); rowNum++)
    {
        RoomIdItem = ui->tableRoomState->item(rowNum, ROOMID);
        if(RoomIdItem->text().toInt() == RoomId)
        {
            StatusItem = ui->tableRoomState->item(rowNum, STATUS);
            if(StatusItem->text().compare(QStringLiteral("已退房")) == 0) continue;
            setCenterTableItem(rowNum, STATUS, text, STATUS);
            break;
        }
    }
}
//往表格填充一个居中格
void AdminController::setCenterTableItem(int row, int col, QString text, int type)
{
    if(!text.compare(QString::asprintf("%d", UNKNOW)))
            text.sprintf("-");
    QTableWidgetItem *item;//单元格对象
    item = new QTableWidgetItem(text, type);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//居中对齐
    ui->tableRoomState->setItem(row, col, item);
}
