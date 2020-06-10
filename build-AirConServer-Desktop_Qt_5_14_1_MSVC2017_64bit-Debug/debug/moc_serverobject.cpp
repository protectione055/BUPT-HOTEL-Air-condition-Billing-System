/****************************************************************************
** Meta object code from reading C++ file 'serverobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AirConServer/serverobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerObject_t {
    QByteArrayData data[14];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerObject_t qt_meta_stringdata_ServerObject = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerObject"
QT_MOC_LITERAL(1, 13, 13), // "RefreshSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "RoomId"
QT_MOC_LITERAL(4, 35, 8), // "Duartion"
QT_MOC_LITERAL(5, 44, 10), // "TargetTemp"
QT_MOC_LITERAL(6, 55, 8), // "FanSpeed"
QT_MOC_LITERAL(7, 64, 11), // "CurrentTemp"
QT_MOC_LITERAL(8, 76, 3), // "Fee"
QT_MOC_LITERAL(9, 80, 18), // "PauseServingSignal"
QT_MOC_LITERAL(10, 99, 19), // "ResumeServingSignal"
QT_MOC_LITERAL(11, 119, 16), // "StartServingRoom"
QT_MOC_LITERAL(12, 136, 16), // "PauseServingRoom"
QT_MOC_LITERAL(13, 153, 6) // "Charge"

    },
    "ServerObject\0RefreshSignal\0\0RoomId\0"
    "Duartion\0TargetTemp\0FanSpeed\0CurrentTemp\0"
    "Fee\0PauseServingSignal\0ResumeServingSignal\0"
    "StartServingRoom\0PauseServingRoom\0"
    "Charge"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   44,    2, 0x06 /* Public */,
       9,    1,   57,    2, 0x06 /* Public */,
      10,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   63,    2, 0x0a /* Public */,
      12,    0,   64,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Float,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ServerObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RefreshSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6]))); break;
        case 1: _t->PauseServingSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ResumeServingSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->StartServingRoom(); break;
        case 4: _t->PauseServingRoom(); break;
        case 5: _t->Charge(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerObject::*)(int , int , int , int , int , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerObject::RefreshSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerObject::PauseServingSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerObject::ResumeServingSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerObject::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ServerObject.data,
    qt_meta_data_ServerObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ServerObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ServerObject::RefreshSignal(int _t1, int _t2, int _t3, int _t4, int _t5, float _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerObject::PauseServingSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ServerObject::ResumeServingSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
