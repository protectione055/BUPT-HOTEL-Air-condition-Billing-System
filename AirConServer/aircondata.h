#ifndef AIRCONDATA_H
#define AIRCONDATA_H

//一些共享的数据声明
#define CPU_COUNT 4                                                  //CPU数量
#define THREAD_COUNT 2*CPU_COUNT+1                                   //最大线程数
#define UNKNOW -274  //空调系统参数默认值，客户端关机时设置

typedef enum TempMode{HOT, COLD} TempMode;
enum FanMode{Low, Middle, High};
typedef enum ServerObjectStatus{RESUME, PAUSE, STOP} ServerStatus;

typedef struct SystemTempLimit
{
    int Highest;
    int Lowest;
}SystemTempLimit;


#endif // AIRCONDATA_H


