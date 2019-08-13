/****************************************************************************
** Meta object code from reading C++ file 'LogicController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Controller/LogicController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogicController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogicController_t {
    QByteArrayData data[17];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogicController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogicController_t qt_meta_stringdata_LogicController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LogicController"
QT_MOC_LITERAL(1, 16, 20), // "sig_camera_el_online"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "bOnline"
QT_MOC_LITERAL(4, 46, 13), // "sig_ImageOver"
QT_MOC_LITERAL(5, 60, 15), // "sig_el_img_over"
QT_MOC_LITERAL(6, 76, 6), // "nIndex"
QT_MOC_LITERAL(7, 83, 16), // "slot_el_img_over"
QT_MOC_LITERAL(8, 100, 19), // "slot_CamCheck_timer"
QT_MOC_LITERAL(9, 120, 21), // "slot_camera_el_online"
QT_MOC_LITERAL(10, 142, 14), // "slot_ImageOver"
QT_MOC_LITERAL(11, 157, 12), // "slot_ELAlgOK"
QT_MOC_LITERAL(12, 170, 1), // "n"
QT_MOC_LITERAL(13, 172, 11), // "slot_el_cmd"
QT_MOC_LITERAL(14, 184, 4), // "nCmd"
QT_MOC_LITERAL(15, 189, 14), // "slot_Save_Over"
QT_MOC_LITERAL(16, 204, 7) // "strPath"

    },
    "LogicController\0sig_camera_el_online\0"
    "\0bOnline\0sig_ImageOver\0sig_el_img_over\0"
    "nIndex\0slot_el_img_over\0slot_CamCheck_timer\0"
    "slot_camera_el_online\0slot_ImageOver\0"
    "slot_ELAlgOK\0n\0slot_el_cmd\0nCmd\0"
    "slot_Save_Over\0strPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogicController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   71,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      10,    0,   78,    2, 0x0a /* Public */,
      11,    1,   79,    2, 0x0a /* Public */,
      13,    1,   82,    2, 0x0a /* Public */,
      15,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void LogicController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogicController *_t = static_cast<LogicController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_camera_el_online((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sig_ImageOver(); break;
        case 2: _t->sig_el_img_over((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_el_img_over((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_CamCheck_timer(); break;
        case 5: _t->slot_camera_el_online((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slot_ImageOver(); break;
        case 7: _t->slot_ELAlgOK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_el_cmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slot_Save_Over((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LogicController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicController::sig_camera_el_online)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LogicController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicController::sig_ImageOver)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LogicController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicController::sig_el_img_over)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LogicController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LogicController.data,
      qt_meta_data_LogicController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LogicController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogicController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LogicController.stringdata0))
        return static_cast<void*>(const_cast< LogicController*>(this));
    return QObject::qt_metacast(_clname);
}

int LogicController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void LogicController::sig_camera_el_online(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LogicController::sig_ImageOver()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void LogicController::sig_el_img_over(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
