/****************************************************************************
** Meta object code from reading C++ file 'elevator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../elevator.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elevator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSElevatorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSElevatorENDCLASS = QtMocHelpers::stringData(
    "Elevator",
    "isIdle",
    "",
    "door_status_changed",
    "door_status",
    "status_changed",
    "status",
    "outerButton",
    "num",
    "moveTo",
    "emStop",
    "update_position_label",
    "value",
    "update_doorstatus_label",
    "update_status_label",
    "btn_openDoor",
    "btn_closeDoor"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSElevatorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    1,   81,    2, 0x06,    2 /* Public */,
       5,    1,   84,    2, 0x06,    4 /* Public */,
       7,    1,   87,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   90,    2, 0x08,    8 /* Private */,
      10,    0,   91,    2, 0x08,    9 /* Private */,
      11,    1,   92,    2, 0x08,   10 /* Private */,
      13,    1,   95,    2, 0x08,   12 /* Private */,
      14,    1,   98,    2, 0x08,   14 /* Private */,
      15,    0,  101,    2, 0x08,   16 /* Private */,
      16,    0,  102,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Elevator::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSElevatorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSElevatorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSElevatorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Elevator, std::true_type>,
        // method 'isIdle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'door_status_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'status_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'outerButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'moveTo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'emStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_position_label'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'update_doorstatus_label'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'update_status_label'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'btn_openDoor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btn_closeDoor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Elevator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Elevator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->isIdle(); break;
        case 1: _t->door_status_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->status_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->outerButton((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->moveTo(); break;
        case 5: _t->emStop(); break;
        case 6: _t->update_position_label((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->update_doorstatus_label((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->update_status_label((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->btn_openDoor(); break;
        case 10: _t->btn_closeDoor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Elevator::*)();
            if (_t _q_method = &Elevator::isIdle; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (_t _q_method = &Elevator::door_status_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (_t _q_method = &Elevator::status_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (_t _q_method = &Elevator::outerButton; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *Elevator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Elevator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSElevatorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Elevator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Elevator::isIdle()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Elevator::door_status_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Elevator::status_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Elevator::outerButton(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
