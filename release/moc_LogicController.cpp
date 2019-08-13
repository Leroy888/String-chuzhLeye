/****************************************************************************
** Meta object code from reading C++ file 'LogicController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Controller/LogicController.h"
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
    QByteArrayData data[29];
    char stringdata0[338];
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
QT_MOC_LITERAL(13, 172, 10), // "OnAidefect"
QT_MOC_LITERAL(14, 183, 11), // "slot_el_cmd"
QT_MOC_LITERAL(15, 195, 4), // "nCmd"
QT_MOC_LITERAL(16, 200, 4), // "args"
QT_MOC_LITERAL(17, 205, 19), // "slot_stopElCmdTimer"
QT_MOC_LITERAL(18, 225, 10), // "OnSaveWPEL"
QT_MOC_LITERAL(19, 236, 14), // "slot_Save_Over"
QT_MOC_LITERAL(20, 251, 7), // "strPath"
QT_MOC_LITERAL(21, 259, 9), // "SlotImage"
QT_MOC_LITERAL(22, 269, 5), // "image"
QT_MOC_LITERAL(23, 275, 3), // "bOK"
QT_MOC_LITERAL(24, 279, 14), // "vector<string>"
QT_MOC_LITERAL(25, 294, 8), // "ElDefect"
QT_MOC_LITERAL(26, 303, 10), // "ElPosition"
QT_MOC_LITERAL(27, 314, 9), // "resDefect"
QT_MOC_LITERAL(28, 324, 13) // "slot_Ai_error"

    },
    "LogicController\0sig_camera_el_online\0"
    "\0bOnline\0sig_ImageOver\0sig_el_img_over\0"
    "nIndex\0slot_el_img_over\0slot_CamCheck_timer\0"
    "slot_camera_el_online\0slot_ImageOver\0"
    "slot_ELAlgOK\0n\0OnAidefect\0slot_el_cmd\0"
    "nCmd\0args\0slot_stopElCmdTimer\0OnSaveWPEL\0"
    "slot_Save_Over\0strPath\0SlotImage\0image\0"
    "bOK\0vector<string>\0ElDefect\0ElPosition\0"
    "resDefect\0slot_Ai_error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogicController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   96,    2, 0x0a /* Public */,
       8,    0,   99,    2, 0x0a /* Public */,
       9,    1,  100,    2, 0x0a /* Public */,
      10,    0,  103,    2, 0x0a /* Public */,
      11,    1,  104,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,
      14,    2,  108,    2, 0x0a /* Public */,
      17,    0,  113,    2, 0x0a /* Public */,
      18,    2,  114,    2, 0x0a /* Public */,
      19,    1,  119,    2, 0x0a /* Public */,
      21,    6,  122,    2, 0x0a /* Public */,
      28,    0,  135,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,   15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,   15,   16,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool, 0x80000000 | 24, 0x80000000 | 24, QMetaType::Int, 0x80000000 | 24,   22,   23,   25,   26,    6,   27,
    QMetaType::Void,

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
        case 8: _t->OnAidefect(); break;
        case 9: _t->slot_el_cmd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 10: _t->slot_stopElCmdTimer(); break;
        case 11: _t->OnSaveWPEL((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 12: _t->slot_Save_Over((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->SlotImage((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3])),(*reinterpret_cast< vector<string>(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< vector<string>(*)>(_a[6]))); break;
        case 14: _t->slot_Ai_error(); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
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
