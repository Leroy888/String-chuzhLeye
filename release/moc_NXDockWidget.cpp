/****************************************************************************
** Meta object code from reading C++ file 'NXDockWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../View/NXDockWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NXDockWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NXDockWidget_t {
    QByteArrayData data[9];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NXDockWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NXDockWidget_t qt_meta_stringdata_NXDockWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "NXDockWidget"
QT_MOC_LITERAL(1, 13, 13), // "signal_pinned"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "NXDockWidget*"
QT_MOC_LITERAL(4, 42, 10), // "dockWidget"
QT_MOC_LITERAL(5, 53, 15), // "signal_unpinned"
QT_MOC_LITERAL(6, 69, 13), // "signal_docked"
QT_MOC_LITERAL(7, 83, 15), // "signal_undocked"
QT_MOC_LITERAL(8, 99, 15) // "slot_menuAction"

    },
    "NXDockWidget\0signal_pinned\0\0NXDockWidget*\0"
    "dockWidget\0signal_unpinned\0signal_docked\0"
    "signal_undocked\0slot_menuAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NXDockWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void NXDockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NXDockWidget *_t = static_cast<NXDockWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_pinned((*reinterpret_cast< NXDockWidget*(*)>(_a[1]))); break;
        case 1: _t->signal_unpinned((*reinterpret_cast< NXDockWidget*(*)>(_a[1]))); break;
        case 2: _t->signal_docked((*reinterpret_cast< NXDockWidget*(*)>(_a[1]))); break;
        case 3: _t->signal_undocked((*reinterpret_cast< NXDockWidget*(*)>(_a[1]))); break;
        case 4: _t->slot_menuAction(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NXDockWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NXDockWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NXDockWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NXDockWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NXDockWidget::*_t)(NXDockWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NXDockWidget::signal_pinned)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NXDockWidget::*_t)(NXDockWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NXDockWidget::signal_unpinned)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NXDockWidget::*_t)(NXDockWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NXDockWidget::signal_docked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NXDockWidget::*_t)(NXDockWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NXDockWidget::signal_undocked)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject NXDockWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_NXDockWidget.data,
      qt_meta_data_NXDockWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NXDockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NXDockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NXDockWidget.stringdata0))
        return static_cast<void*>(const_cast< NXDockWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int NXDockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void NXDockWidget::signal_pinned(NXDockWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NXDockWidget::signal_unpinned(NXDockWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NXDockWidget::signal_docked(NXDockWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NXDockWidget::signal_undocked(NXDockWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
