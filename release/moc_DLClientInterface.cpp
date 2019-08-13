/****************************************************************************
** Meta object code from reading C++ file 'DLClientInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Model/DLClientInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DLClientInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DLClientInterface_t {
    QByteArrayData data[13];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DLClientInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DLClientInterface_t qt_meta_stringdata_DLClientInterface = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DLClientInterface"
QT_MOC_LITERAL(1, 18, 7), // "sig_Img"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "image"
QT_MOC_LITERAL(4, 33, 3), // "bOK"
QT_MOC_LITERAL(5, 37, 14), // "vector<string>"
QT_MOC_LITERAL(6, 52, 10), // "m_ElDefect"
QT_MOC_LITERAL(7, 63, 12), // "m_ElPosition"
QT_MOC_LITERAL(8, 76, 5), // "index"
QT_MOC_LITERAL(9, 82, 12), // "sig_Ai_error"
QT_MOC_LITERAL(10, 95, 10), // "slot_Image"
QT_MOC_LITERAL(11, 106, 5), // "Image"
QT_MOC_LITERAL(12, 112, 13) // "slot_Ai_error"

    },
    "DLClientInterface\0sig_Img\0\0image\0bOK\0"
    "vector<string>\0m_ElDefect\0m_ElPosition\0"
    "index\0sig_Ai_error\0slot_Image\0Image\0"
    "slot_Ai_error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DLClientInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   34,    2, 0x06 /* Public */,
       9,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    6,   48,    2, 0x0a /* Public */,
      12,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,    7,    8,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, 0x80000000 | 5,   11,    4,    6,    7,    8,    2,
    QMetaType::Void,

       0        // eod
};

void DLClientInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DLClientInterface *_t = static_cast<DLClientInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_Img((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3])),(*reinterpret_cast< vector<string>(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< vector<string>(*)>(_a[6]))); break;
        case 1: _t->sig_Ai_error(); break;
        case 2: _t->slot_Image((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< vector<string>(*)>(_a[3])),(*reinterpret_cast< vector<string>(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< vector<string>(*)>(_a[6]))); break;
        case 3: _t->slot_Ai_error(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DLClientInterface::*_t)(const QImage & , bool , vector<string> , vector<string> , int , vector<string> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DLClientInterface::sig_Img)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DLClientInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DLClientInterface::sig_Ai_error)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DLClientInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DLClientInterface.data,
      qt_meta_data_DLClientInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DLClientInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DLClientInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DLClientInterface.stringdata0))
        return static_cast<void*>(const_cast< DLClientInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int DLClientInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void DLClientInterface::sig_Img(const QImage & _t1, bool _t2, vector<string> _t3, vector<string> _t4, int _t5, vector<string> _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DLClientInterface::sig_Ai_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
