/****************************************************************************
** Meta object code from reading C++ file 'ELCmdAction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../View/ELCmdAction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ELCmdAction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ELCmdAction_t {
    QByteArrayData data[12];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ELCmdAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ELCmdAction_t qt_meta_stringdata_ELCmdAction = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ELCmdAction"
QT_MOC_LITERAL(1, 12, 7), // "sig_cmd"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 26), // "on_BTN_SAVE_EL_DIR_clicked"
QT_MOC_LITERAL(4, 48, 28), // "on_BTN_SAVE_EL_DIR_2_clicked"
QT_MOC_LITERAL(5, 77, 28), // "on_BTN_SAVE_EL_DIR_3_clicked"
QT_MOC_LITERAL(6, 106, 23), // "on_pushButton_1_clicked"
QT_MOC_LITERAL(7, 130, 18), // "on_Btn_OK2_clicked"
QT_MOC_LITERAL(8, 149, 17), // "on_Btn_NG_clicked"
QT_MOC_LITERAL(9, 167, 17), // "on_Btn_OK_clicked"
QT_MOC_LITERAL(10, 185, 7), // "OnClick"
QT_MOC_LITERAL(11, 193, 3) // "cmd"

    },
    "ELCmdAction\0sig_cmd\0\0on_BTN_SAVE_EL_DIR_clicked\0"
    "on_BTN_SAVE_EL_DIR_2_clicked\0"
    "on_BTN_SAVE_EL_DIR_3_clicked\0"
    "on_pushButton_1_clicked\0on_Btn_OK2_clicked\0"
    "on_Btn_NG_clicked\0on_Btn_OK_clicked\0"
    "OnClick\0cmd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ELCmdAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   64,    2, 0x08 /* Private */,
       4,    0,   65,    2, 0x08 /* Private */,
       5,    0,   66,    2, 0x08 /* Private */,
       6,    0,   67,    2, 0x08 /* Private */,
       7,    0,   68,    2, 0x08 /* Private */,
       8,    0,   69,    2, 0x0a /* Public */,
       9,    0,   70,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void ELCmdAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ELCmdAction *_t = static_cast<ELCmdAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_cmd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->on_BTN_SAVE_EL_DIR_clicked(); break;
        case 2: _t->on_BTN_SAVE_EL_DIR_2_clicked(); break;
        case 3: _t->on_BTN_SAVE_EL_DIR_3_clicked(); break;
        case 4: _t->on_pushButton_1_clicked(); break;
        case 5: _t->on_Btn_OK2_clicked(); break;
        case 6: _t->on_Btn_NG_clicked(); break;
        case 7: _t->on_Btn_OK_clicked(); break;
        case 8: _t->OnClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ELCmdAction::*_t)(int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ELCmdAction::sig_cmd)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ELCmdAction::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ELCmdAction.data,
      qt_meta_data_ELCmdAction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ELCmdAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ELCmdAction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ELCmdAction.stringdata0))
        return static_cast<void*>(const_cast< ELCmdAction*>(this));
    return QWidget::qt_metacast(_clname);
}

int ELCmdAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ELCmdAction::sig_cmd(int _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
