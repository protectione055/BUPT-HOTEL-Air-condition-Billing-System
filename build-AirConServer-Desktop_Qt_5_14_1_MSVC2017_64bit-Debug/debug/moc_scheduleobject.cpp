/****************************************************************************
** Meta object code from reading C++ file 'scheduleobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AirConServer/scheduleobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scheduleobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScheduleObject_t {
    QByteArrayData data[15];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScheduleObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScheduleObject_t qt_meta_stringdata_ScheduleObject = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ScheduleObject"
QT_MOC_LITERAL(1, 15, 17), // "ServerObjectStart"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "RoomId"
QT_MOC_LITERAL(4, 41, 9), // "StartTime"
QT_MOC_LITERAL(5, 51, 14), // "Refresh_Signal"
QT_MOC_LITERAL(6, 66, 8), // "Duartion"
QT_MOC_LITERAL(7, 75, 10), // "TargetTemp"
QT_MOC_LITERAL(8, 86, 8), // "FanSpeed"
QT_MOC_LITERAL(9, 95, 11), // "CurrentTemp"
QT_MOC_LITERAL(10, 107, 3), // "Fee"
QT_MOC_LITERAL(11, 111, 17), // "ServerObjectPause"
QT_MOC_LITERAL(12, 129, 18), // "ServerObjectResume"
QT_MOC_LITERAL(13, 148, 16), // "ServerObjectStop"
QT_MOC_LITERAL(14, 165, 20) // "ServerObjectSchedule"

    },
    "ScheduleObject\0ServerObjectStart\0\0"
    "RoomId\0StartTime\0Refresh_Signal\0"
    "Duartion\0TargetTemp\0FanSpeed\0CurrentTemp\0"
    "Fee\0ServerObjectPause\0ServerObjectResume\0"
    "ServerObjectStop\0ServerObjectSchedule"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScheduleObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    6,   49,    2, 0x06 /* Public */,
      11,    1,   62,    2, 0x06 /* Public */,
      12,    1,   65,    2, 0x06 /* Public */,
      13,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QTime,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Float,    3,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ScheduleObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScheduleObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ServerObjectStart((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        case 1: _t->Refresh_Signal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6]))); break;
        case 2: _t->ServerObjectPause((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ServerObjectResume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ServerObjectStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ServerObjectSchedule((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScheduleObject::*)(int , QTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScheduleObject::ServerObjectStart)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScheduleObject::*)(int , int , int , int , int , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScheduleObject::Refresh_Signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScheduleObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScheduleObject::ServerObjectPause)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ScheduleObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScheduleObject::ServerObjectResume)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ScheduleObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScheduleObject::ServerObjectStop)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScheduleObject::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScheduleObject.data,
    qt_meta_data_ScheduleObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScheduleObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScheduleObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScheduleObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScheduleObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ScheduleObject::ServerObjectStart(int _t1, QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScheduleObject::Refresh_Signal(int _t1, int _t2, int _t3, int _t4, int _t5, float _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScheduleObject::ServerObjectPause(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ScheduleObject::ServerObjectResume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ScheduleObject::ServerObjectStop(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
