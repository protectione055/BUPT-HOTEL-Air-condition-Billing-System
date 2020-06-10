#ifndef SCHEDULEOBJECT_H
#define SCHEDULEOBJECT_H

#include <QObject>
#include<QMap>
#include<QThread>
#include "serverobject.h"
#include "aircondata.h"

class ScheduleObject: public QObject
{
    Q_OBJECT
public:
    ScheduleObject(SystemTempLimit inTempLimit, bool *inMode, float* inFeeRate);
    ~ScheduleObject();
    int countServerObject();
    void setTempLimit(SystemTempLimit inTempLimit);//从ac接收温度限制更改
    void setFeeRate(float* inFeeRate);//从ac接收费率更改
    void createServerObject(int inRoomId);//入住调用，创建调度对象
    void stopServerObject(int inRoomId);//强制使服务对象进入待机状态
    void destroyServerObject(int inRoomId);//退房，服务对象从对象集删除

private:
    QMap<int, ServerObject*> ServerSet;//所有调度对象的集合，用RoomId索引
    QList<int> ServerList;//队列存储房号
    QList<int> WaitingList;
    bool *Mode;
    SystemTempLimit TempLimit;//温度限制参数
    float *FeeRate;//费率参数
    //void startServrObject();
    //从客户端接收并解析请求
    //

private slots:
    void ServerObjectSchedule(int RoomId);//服务对象发出pause信号时调用，从等待队列调度一个等待对象


signals:
    void ServerObjectStart(int RoomId, QTime StartTime);//准备服务
    void Refresh_Signal(int RoomId, int Duartion, int TargetTemp, int FanSpeed, int CurrentTemp, float Fee);  //调度对象服务完一个周期发送信号修改表格
    void ServerObjectPause(int RoomId);    //分配的时间片完成
    void ServerObjectResume(int RoomId);   //服务对象进入服务队列开始服务
    void ServerObjectStop(int RoomId); //结束服务时发送
};

#endif // SCHEDULEOBJECT_H
