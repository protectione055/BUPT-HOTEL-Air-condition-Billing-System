#include "scheduleobject.h"
#include<QDebug>


//构造函数
ScheduleObject::ScheduleObject(SystemTempLimit inTempLimit, bool *inMode, float *inFeeRate)
{
    Mode = inMode;
    this->TempLimit = inTempLimit;
    this->FeeRate = inFeeRate;
}
//TODO析构函数
ScheduleObject::~ScheduleObject()
{
    while(!ServerList.isEmpty())
    {
        //TODO: 杀死服务线程
        break;
    }
    //TODO: 删除等待对象
    QMutableListIterator<int> j(WaitingList);
    while(j.hasNext())
    {
        j.next();
#ifdef  _DEBUG
        qDebug()<<"移除等待对象:"<<j.value();
#endif
        j.remove();
    }
}

//返回服务对象数目
int ScheduleObject::countServerObject()
{
    int count = 0;
    QMapIterator<int, ServerObject*> i(ServerSet);
    while(i.hasNext())
    {
        if(i.next().value() !=NULL)
            ++count;
    }
    return count;
}

//设置调度对象温度限制
void ScheduleObject::setTempLimit(SystemTempLimit inTempLimit)
{
    TempLimit = inTempLimit;
    //遍历所有调度对象，修改温度
    QMutableMapIterator<int, ServerObject*> i(ServerSet);
    while(i.hasNext())
    {
        ServerObject* tempServer = i.next().value();
        int tarTemp = tempServer->getTargetTemp();
        if(tarTemp != UNKNOW && tarTemp < inTempLimit.Lowest)
            tempServer->setTargetTemp(inTempLimit.Lowest);
        else if(tarTemp > inTempLimit.Highest)
            tempServer->setTargetTemp(inTempLimit.Highest);
    }
}

//创建服务对象
void ScheduleObject::createServerObject(int inRoomId)
{
    ServerObject *newServerObject;
    newServerObject = new ServerObject(inRoomId, UNKNOW, UNKNOW, UNKNOW, FeeRate, Mode);
    ServerSet[inRoomId] = newServerObject;//新服务对象入对象集

    emit ServerObjectStart(inRoomId, newServerObject->getStartTime());//发射信号告知ac调度对象新建成功

    connect(newServerObject, SIGNAL(RefreshSignal(int, int, int, int, int, float)), this, SIGNAL(Refresh_Signal(int, int, int, int, int, float)));
    connect(newServerObject, SIGNAL(PauseServingSignal(int)), this, SIGNAL(ServerObjectPause(int)));
    //connect(newServerObject, SIGNAL(PauseServingSignal(int)), this, SLOT(ServerObjectSchedule(int)));
    connect(newServerObject, SIGNAL(ResumeServingSignal(int)), this, SIGNAL(ServerObjectResume(int)));

#ifdef _DEBUG
    newServerObject->setFanSpeed(Middle);
    newServerObject->setTargetTemp(16);
    newServerObject->setCurrentTemp(20);
    newServerObject->StartServingRoom();
#endif

}
//TODO客户端关机但是还没有退房，服务对象从等待队列和调度队列中退出
void ScheduleObject::stopServerObject(int inRoomId)
{
    ServerObject *tempObject;

    //从等待队列退出
    QMutableListIterator<int> i(WaitingList);
    while(i.hasNext())
    {
        i.next();
        tempObject = ServerSet[i.value()];
        if(inRoomId == tempObject->getRoomId())
        {
            i.remove();
            ServerSet[inRoomId]->Status = STOP;
            emit ServerObjectStop(inRoomId);//RoomId关机
            break;
        }
    }

    return;

    //TODO:杀死线程,从服务队列退出
//    QMutableListIterator<ServerObject*> j(ServerList);
//    while(j.hasNext())
//    {
//        j.next();
//        tempObject = j.value();
//        if(inRoomId == tempObject->getRoomId())
//        {
//            j.remove();
            //switchServerSchedule(inRoomId);
//            break;
//        }
//    }
    ServerSet[inRoomId]->Status = STOP;
    emit ServerObjectStop(inRoomId);//RoomId关机
}
//客户退房，删除服务对象
void ScheduleObject::destroyServerObject(int inRoomId)
{
    stopServerObject(inRoomId);
    delete ServerSet[inRoomId];
    ServerSet[inRoomId] = NULL;
}

/*TODO服务队列调度
 * 在此执行服务对象的调度和线程创建
 * 调用ServerObject->StartServingRoom()方法开始执行线程,ServerObject->PauseServingRoom()停止执行
 * 主要步骤:
 * 1.客户机发来开机消息,将对应服务对象指针从ServerSet[RoomId]放入WaitingList,
 * WaitingList.append(ServerSet[RoomId]执行入列，ServerSet[RoomId]调用PauseServingRoom()进入等待状态
 * 调用ServerObjectSchedule()进行调度。
 * 2.客户端发来参数更改
 * 调用ServerSet[RoomID]的"set参数"方法更改即可
 * 3.客户端发来关机消息
 * 调用scheduler的stopServerObject(RoomId)方法;
 * *********************************************/
void ScheduleObject::ServerObjectSchedule(int RoomId)
{
    return;
}
