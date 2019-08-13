/****************************************************************************
** Meta object code from reading C++ file 'SysSetAction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../View/SysSetAction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SysSetAction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SysSetAction_t {
    QByteArrayData data[10];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SysSetAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SysSetAction_t qt_meta_stringdata_SysSetAction = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SysSetAction"
QT_MOC_LITERAL(1, 13, 21), // "on_Btn_SysSet_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 25), // "on_comboBox_ini_activated"
QT_MOC_LITERAL(4, 62, 4), // "arg1"
QT_MOC_LITERAL(5, 67, 29), // "on_pushButton_WG_SAVE_clicked"
QT_MOC_LITERAL(6, 97, 29), // "on_pushButton_EL_SAVE_clicked"
QT_MOC_LITERAL(7, 127, 33), // "on_pushButton_ClearBuffer_cli..."
QT_MOC_LITERAL(8, 161, 28), // "on_pushButton_ReSend_clicked"
QT_MOC_LITERAL(9, 190, 21) // "on_pushButton_clicked"

    },
    "SysSetAction\0on_Btn_SysSet_clicked\0\0"
    "on_comboBox_ini_activated\0arg1\0"
    "on_pushButton_WG_SAVE_clicked\0"
    "on_pushButton_EL_SAVE_clicked\0"
    "on_pushButton_ClearBuffer_clicked\0"
    "on_pushButton_ReSend_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysSetAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SysSetAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SysSetAction *_t = static_cast<SysSetAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Btn_SysSet_clicked(); break;
        case 1: _t->on_comboBox_ini_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_WG_SAVE_clicked(); break;
        case 3: _t->on_pushButton_EL_SAVE_clicked(); break;
        case 4: _t->on_pushButton_ClearBuffer_clicked(); break;
        case 5: _t->on_pushButton_ReSend_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SysSetAction::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SysSetAction.data,
      qt_meta_data_SysSetAction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SysSetAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SysSetAction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SysSetAction.stringdata0))
        return static_cast<void*>(const_cast< SysSetAction*>(this));
    return QWidget::qt_metacast(_clname);
}

int SysSetAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
