/****************************************************************************
** Meta object code from reading C++ file 'simthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gwentCalc/simthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimThread_t {
    QByteArrayData data[13];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimThread_t qt_meta_stringdata_SimThread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SimThread"
QT_MOC_LITERAL(1, 10, 14), // "percentChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "simulationComplete"
QT_MOC_LITERAL(4, 45, 15), // "GwentSimResults"
QT_MOC_LITERAL(5, 61, 18), // "pIterationsChanged"
QT_MOC_LITERAL(6, 80, 15), // "hideProgressBar"
QT_MOC_LITERAL(7, 96, 9), // "showLabel"
QT_MOC_LITERAL(8, 106, 9), // "hideLabel"
QT_MOC_LITERAL(9, 116, 15), // "setMessageLabel"
QT_MOC_LITERAL(10, 132, 15), // "showProgressBar"
QT_MOC_LITERAL(11, 148, 9), // "plotPoint"
QT_MOC_LITERAL(12, 158, 12) // "refreshChart"

    },
    "SimThread\0percentChanged\0\0simulationComplete\0"
    "GwentSimResults\0pIterationsChanged\0"
    "hideProgressBar\0showLabel\0hideLabel\0"
    "setMessageLabel\0showProgressBar\0"
    "plotPoint\0refreshChart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,
       8,    0,   75,    2, 0x06 /* Public */,
       9,    1,   76,    2, 0x06 /* Public */,
      10,    0,   79,    2, 0x06 /* Public */,
      11,    2,   80,    2, 0x06 /* Public */,
      12,    0,   85,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    2,    2,
    QMetaType::Void,

       0        // eod
};

void SimThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimThread *_t = static_cast<SimThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->percentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->simulationComplete((*reinterpret_cast< GwentSimResults(*)>(_a[1]))); break;
        case 2: _t->pIterationsChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->hideProgressBar(); break;
        case 4: _t->showLabel(); break;
        case 5: _t->hideLabel(); break;
        case 6: _t->setMessageLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->showProgressBar(); break;
        case 8: _t->plotPoint((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 9: _t->refreshChart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GwentSimResults >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SimThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::percentChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SimThread::*)(GwentSimResults );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::simulationComplete)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SimThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::pIterationsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SimThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::hideProgressBar)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SimThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::showLabel)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SimThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::hideLabel)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SimThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::setMessageLabel)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SimThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::showProgressBar)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SimThread::*)(qreal , qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::plotPoint)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SimThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimThread::refreshChart)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SimThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SimThread.data,
      qt_meta_data_SimThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SimThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SimThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SimThread::percentChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimThread::simulationComplete(GwentSimResults _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SimThread::pIterationsChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SimThread::hideProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SimThread::showLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SimThread::hideLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SimThread::setMessageLabel(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SimThread::showProgressBar()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SimThread::plotPoint(qreal _t1, qreal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SimThread::refreshChart()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
