#include "serverobject.h"
#include<QDebug>

/*服务对象ServerObeject
 * @author:张子鸣
 * 有三个状态:工作中RESUME, 等待中PAUSE, 待机中STOP, 每个实例状态由Status字段保存
 * 每次切换状态都会向scheduler发射相应的信号，由scheduler进行下一步处理和信号转发
 * 可以调用StartServingRoom()、PauseServingRoom()使服务对象进入工作状态和等待状态
 * ************************************************************************/

//构造函数
ServerObject::ServerObject(int inRoomId, int inTargetTemp, int inFanSpeed, int inCurrentTemp, float *inFeeRate, bool *inMode):
RoomId(inRoomId), TargetTemp(inTargetTemp), FanSpeed(inFanSpeed), CurrentTemp(inCurrentTemp)
{
    Status = STOP;
    Duration = 0;
    Fee = 0;//费用初始化为0
    FeeRate = inFeeRate;
    Mode = inMode;

    //设置调度对象定时器
    StartTime = QTime::currentTime();//服务对象开始时间
    ChargingTimer = new QTimer(this);
    ChargingTimer->stop();
    ChargingTimer->setInterval(1000);//计费时间设定为1秒
    ServerTimer = new QTimer(this);
    ServerTimer->stop();
    ServerTimer->setInterval(3100);//时间片设定为3秒,预留100毫秒程序相应时间

    connect(ServerTimer, SIGNAL(timeout()), this, SLOT(PauseServingRoom()));//时间片超时
    connect(ChargingTimer, SIGNAL(timeout()), this, SLOT(Charge()));//每秒计费

#ifdef _DEBUG
    qDebug()<<"调度对象房间号: "<<RoomId;
    qDebug()<<"开始时间: "<<StartTime.toString("hh:mm:ss");
#endif
}
//析构函数，返回结束的房间id
ServerObject::~ServerObject()
{
    delete ChargingTimer;
    delete ServerTimer;
}

//获得房间ID
int ServerObject::getRoomId()
{
    return this->RoomId;
}
//获得开始时间
QTime ServerObject::getStartTime()
{
    return StartTime;
}
//获得目标温度
int ServerObject::getTargetTemp()
{
    return this->TargetTemp;
}
//获得风速
int ServerObject::getFanSpeed()
{
    return this->FanSpeed;
}
//获得费用
float ServerObject::getFee()
{
    return this->Fee;
}

//设置目标温度
void ServerObject::setTargetTemp(int inTargetTemp)
{
    this->TargetTemp = inTargetTemp;
    emit RefreshSignal(RoomId, Duration, TargetTemp, FanSpeed, CurrentTemp, Fee);
}
//设置风速，随后更改费率
void ServerObject::setFanSpeed(int inFanSpeed)
{
    this->FanSpeed = inFanSpeed;
    emit RefreshSignal(RoomId, Duration, TargetTemp, FanSpeed, CurrentTemp, Fee);
}
//设置当前温度
void ServerObject::setCurrentTemp(int inCurrentTemp)
{
    this->CurrentTemp = inCurrentTemp;
}

//收到主线程startRunning信号时开始服务
void ServerObject::StartServingRoom()
{
    emit RefreshSignal(RoomId, Duration, TargetTemp, FanSpeed, CurrentTemp, Fee);

    if((*Mode ==  COLD && CurrentTemp <= TargetTemp)|| (*Mode == HOT && CurrentTemp >= TargetTemp))
    {
        //向客户端发送完成信号
        PauseServingRoom();
        return;
    }

    Status = RESUME;
    ChargingTimer->start();
    ServerTimer->start();

    emit ResumeServingSignal(RoomId);//通知ac将房间RoomId状态修改为服务中
}
//周期计费
void ServerObject::Charge()
{
#ifdef _DEBUG
    if(*Mode == COLD)
        CurrentTemp--;
    else if(*Mode == HOT)
        CurrentTemp++;
#endif
    //已经无需继续服务
    if(Status != RESUME || (*Mode ==  COLD && CurrentTemp <= TargetTemp) || (*Mode == HOT && CurrentTemp >= TargetTemp))
    {
        //向客户端发送完成信号
        PauseServingRoom();
    }

    //计费
    Duration++;
    Fee += FeeRate[FanSpeed];
    //ac刷新表格，调度对象从客户端收到的当前温度然后更新服务对象当前温度
    emit RefreshSignal(RoomId, Duration, TargetTemp, FanSpeed, CurrentTemp, Fee);
}
//暂停服务
void ServerObject::PauseServingRoom()
{
    Status = PAUSE;
    ServerTimer->stop();
    ChargingTimer->stop();

    emit PauseServingSignal(RoomId);//服务对象挂起信号

    //exit(0);退出线程
}
