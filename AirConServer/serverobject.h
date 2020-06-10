#ifndef SERVEROBJECT_H
#define SERVEROBJECT_H

#include<QObject>
#include<QTime>
#include<QTimer>
#include<QThread>
#include"aircondata.h"

#define SERVE_TIME 2000

class ServerObject :  public QObject
{
    Q_OBJECT

public:
    ServerObject(int inRoomId, int inTargetTemp, int inFanSpeed, int inCurrentTemp, float *FeeRate, bool *Mode);
    ~ServerObject();
    ServerStatus Status;//状态
    int getRoomId();
    QTime getStartTime();
    int getTargetTemp();
    int getFanSpeed();
    float getFee();
    void setTargetTemp(int inTargetTemp);//调度对象调用，设置目标温度
    void setFanSpeed(int inFanSpeed);//调度对象调用，设置目标风速
    void setCurrentTemp(int inCurrentTemp);//调度对象调用，设置房间当前温度

private:
    int RoomId;
    int TargetTemp;
    QTime StartTime;    //服务对象生成时间
    int FanSpeed;
    int Duration;   //服务时长，以秒为单位
    int CurrentTemp;
    float Fee;
    float *FeeRate;
    bool *Mode;
    QTimer *ChargingTimer;  //计费定时器，超时设定为1秒
    QTimer *ServerTimer;    //服务计时器，超时设定为SERVE_TIME

public slots:
    void Charge();//计费
    void StartServingRoom();    //接收主线程startRunning信号，moveToThread时启动计费
    void PauseServingRoom();    //暂停计费，通知scheduler退出服务队列，进入等待对象

signals:
    void RefreshSignal(int RoomId, int Duartion, int TargetTemp, int FanSpeed, int CurrentTemp, float Fee);  //调度对象发送信号修改表格
    void PauseServingSignal(int RoomId);    //分配的时间片完成信号
    void ResumeServingSignal(int RoomId);   //开始计费，通知ac修改状态为:服务中
};

#endif // SERVEROBJECT_H
