#ifndef WAITINGOBJECT_H
#define WAITINGOBJECT_H
/*
 * @author:王浩铭
 * **********************/
#include <QObject>

class WaitingObject : public QObject
{
    Q_OBJECT
public:
    explicit WaitingObject(QObject *parent, int inRoomID,int inFanSpeed,int incurrentTemp,float inFee,int inTargetTemp);
    WaitingObject(int inRoomID,int inFanSpeed,int incurrentTemp,float inFee,int inTargetTemp);//构造函数
    ~WaitingObject();//析构函数
    int getRoomID();
    int getTargetTemp();
    int getFanSpeed();
    int getcurrentTemp();
    //int getwaitDuration();
    float getFee();
    void SetTargetTemp(int inRoomeID,int inTargetTemp);//修改目标温度值
    void SetFanSpeed(int inRoomeID,int inFanSpeed);//修改目标风速

private:
    int RoomID;//房间编号
    int FanSpeed;//目标风速
    int currentTemp;//当前温度
    float Fee;//当前费用
    int waitDuration;//等待时间
    int TargetTemp;//目标温度
signals:

};

#endif // WAITINGOBJECT_H
