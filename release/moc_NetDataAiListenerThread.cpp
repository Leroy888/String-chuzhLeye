/****************************************************************************
** Meta object code from reading C++ file 'NetDataAiListenerThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Model/NetDataAiListenerThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetDataAiListenerThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetDataAiListenerThread_t {
    QByteArrayData data[13];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetDataAiListenerThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetDataAiListenerThread_t qt_meta_stringdata_NetDataAiListenerThread = {
    {
QT_MOC_LITERAL(0, 0, 23), // "NetDataAiListenerThread"
QT_MOC_LITERAL(1, 24, 15), // "sig_waitTimeout"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "sig_Image"
QT_MOC_LITERAL(4, 51, 3), // "img"
QT_MOC_LITERAL(5, 55, 3), // "bOK"
QT_MOC_LITERAL(6, 59, 14), // "vector<string>"
QT_MOC_LITERAL(7, 74, 10), // "m_ElDefect"
QT_MOC_LITERAL(8, 85, 12), // "m_ElPosition"
QT_MOC_LITERAL(9, 98, 5), // "index"
QT_MOC_LITERAL(10, 104, 9), // "resDefect"
QT_MOC_LITERAL(11, 114, 12), // "sig_Ai_error"
QT_MOC_LITERAL(12, 127, 16) // "slot_waitTimeout"

    },
    "NetDataAiListenerThread\0sig_waitTimeout\0"
    "\0sig_Image\0img\0bOK\0vector<string>\0"
    "m_ElDefect\0m_ElPosition\0index\0resDefect\0"
    "sig_Ai_error\0slot_waitTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetDataAiListenerThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    6,   35,    2, 0x06 /* Public */,
      11,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   49,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool, 0x80000000 | 6, 0x80000000 | 6, QMetaType::Int, 0x80000000 | 6,    4,    5,    7,    8,    9,   10,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void NetDataAiListenerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetDataAiListenerThread *_t = static_cast<NetDataAiListenerThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_waitTimeout(); break;
        case 1: _t->sig_Image((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3])),(*reinterpret_cast< vector<string>(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< vector<string>(*)>(_a[6]))); break;
        case 2: _t->sig_Ai_error(); break;
        case 3: _t->slot_waitTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetDataAiListenerThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetDataAiListenerThread::sig_waitTimeout)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetDataAiListenerThread::*_t)(const QImage & , bool , vector<string> , vector<string> , int , vector<string> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetDataAiListenerThread::sig_Image)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetDataAiListenerThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetDataAiListenerThread::sig_Ai_error)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject NetDataAiListenerThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_NetDataAiListenerThread.data,
      qt_meta_data_NetDataAiListenerThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetDataAiListenerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetDataAiListenerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetDataAiListenerThread.stringdata0))
        return static_cast<void*>(const_cast< NetDataAiListenerThread*>(this));
    return QThread::qt_metacast(_clname);
}

int NetDataAiListenerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NetDataAiListenerThread::sig_waitTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void NetDataAiListenerThread::sig_Image(const QImage & _t1, bool _t2, vector<string> _t3, vector<string> _t4, int _t5, vector<string> _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetDataAiListenerThread::sig_Ai_error()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
