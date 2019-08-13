/****************************************************************************
** Meta object code from reading C++ file 'DebugController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Controller/DebugController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DebugController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DebugController_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DebugController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DebugController_t qt_meta_stringdata_DebugController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DebugController"
QT_MOC_LITERAL(1, 16, 9), // "slot_save"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "slot_save_other"
QT_MOC_LITERAL(4, 43, 18) // "slot_Close_windows"

    },
    "DebugController\0slot_save\0\0slot_save_other\0"
    "slot_Close_windows"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DebugController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       3,    1,   32,    2, 0x08 /* Private */,
       4,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void DebugController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DebugController *_t = static_cast<DebugController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->slot_save_other((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slot_Close_windows(); break;
        default: ;
        }
    }
}

const QMetaObject DebugController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DebugController.data,
      qt_meta_data_DebugController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DebugController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DebugController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DebugController.stringdata0))
        return static_cast<void*>(const_cast< DebugController*>(this));
    return QObject::qt_metacast(_clname);
}

int DebugController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
