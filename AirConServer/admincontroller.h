#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include<QTimer>
#include<QTime>
#include "scheduleobject.h"
#include "aircondata.h"
#include "dialogcheckin.h"

#pragma execution_character_set("utf-8")

#define FEERATE_UPPER 12                                             //定义费率上限
#define TEMP_UPPER 32                                                //定义温度上限
#define TEMP_LOWER 16                                                //定义温度下限
//服务对象状态: 待机中、等待中、服务中、已退房

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class AdminController : public QMainWindow
{
    Q_OBJECT

public:
    AdminController(QWidget *parent = nullptr);
    ~AdminController();

    float FeeRate[3];//系统费率

private slots:
    void on_timer_timeout();
    void on_TurnOnButton_clicked();
    void on_TurnOffButton_clicked();
    void on_LFeeSpin_valueChanged(double LowSpeedFeeRate);
    void on_MFeeSpin_valueChanged(double MiddleSpeedFeeRate);
    void on_HFeeSpin_valueChanged(double HighSpeedFeeRate);
    void on_HighestTempSpin_valueChanged(int HighTemp);
    void on_LowestTempSpin_valueChanged(int LowTemp);
    void on_action_checkin_triggered();
    void on_action_checkout_triggered();
    void Table_NewServerObjectCreated(int RoomId, QTime StartTime);//CheckIn时调用,往表中插入新行
    void Table_ServerObjectRefreshed(int RoomId, int Duration, int TargetTemp, int FanSpeed, int CurrentTemp, float Fee);//服务对象更新时修改表格
    void Table_ServerObjectPaused(int RoomId);//服务对象暂停时修改表格
    void Table_ServerObjectStopped(int RoomId);//服务对象待机时修改表格
    void Table_ServerObjectResumed(int RoomId);//服务对象开始服务时修改表格
    void Table_ServerObjectDestroyed(int RoomId);//服务对象被销毁时修改表格
    void on_ModeCold_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    bool SystemStatus;//系统开关机状态
    bool SystemMode;//系统冷热模式:true冷/false热
    SystemTempLimit TempLimit;//系统温度限制
    QTimer *sTimer;//定时器
    QTime sTimeCounter;
    ScheduleObject *scheduler;//调度对象

    enum ColumnIndex{NUM, ROOMID, STARTTIME, DURATION,
                     FANSPEED, CURTEMP, TARGETTEMP, FEE, STATUS};//表格列标

    QLabel *SystemStatusLabel;//开机状态栏
    QLabel *CurrentServeNumLabel;//入住数状态栏
    QLabel *SystemRunTimeLabel;//系统运行时间

    void setCenterTableItem(int row, int col, QString text, int type);//设置居中单元格
    void setRoomStatusItem(int RoomId, QString text);
    int findRoomIdRow(int RoomId);
};

#endif // MAINWINDOW_H
