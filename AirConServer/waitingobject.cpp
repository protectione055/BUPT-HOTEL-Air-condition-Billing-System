#include "waitingobject.h"

/*等待对象
 * @author:王浩铭
 * **********************/

WaitingObject::WaitingObject
(int inRoomID,int inFanSpeed,int incurrentTemp,float inFee,int inTargetTemp)
{
    RoomID=inRoomID;
    FanSpeed=inFanSpeed;
    currentTemp=incurrentTemp;
    Fee=inFee;
    TargetTemp=inTargetTemp;
}

//析构函数
WaitingObject::~WaitingObject()
{

}
//获得房间id
int WaitingObject::getRoomID()
{
    return this->RoomID;
}
//获得目标温度
int WaitingObject::getTargetTemp()
{
    return this->TargetTemp;
}
//获得当前温度
int WaitingObject::getcurrentTemp()
{
    return this->currentTemp;
}
//获得费用
float WaitingObject::getFee()
{
    return this->Fee;
}
//获得目标风速
int WaitingObject::getFanSpeed()
{
   return this->FanSpeed;
}
//改变目标温度
void WaitingObject::SetTargetTemp(int inRoomeID, int inTargetTemp)
{
    this->TargetTemp=inTargetTemp;
}
//改变目标风速
void WaitingObject::SetFanSpeed(int inRoomeID, int inFanSpeed)
{
    this->FanSpeed=inFanSpeed;
}
