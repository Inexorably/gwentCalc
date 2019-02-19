/****************************************************************************
** Meta object code from reading C++ file 'progressdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gwentCalc/progressdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progressdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProgressDialog_t {
    QByteArrayData data[10];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProgressDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProgressDialog_t qt_meta_stringdata_ProgressDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ProgressDialog"
QT_MOC_LITERAL(1, 15, 11), // "closeParent"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "appendPoint"
QT_MOC_LITERAL(4, 40, 1), // "x"
QT_MOC_LITERAL(5, 42, 1), // "y"
QT_MOC_LITERAL(6, 44, 18), // "simulationComplete"
QT_MOC_LITERAL(7, 63, 15), // "GwentSimResults"
QT_MOC_LITERAL(8, 79, 1), // "r"
QT_MOC_LITERAL(9, 81, 21) // "on_pushButton_clicked"

    },
    "ProgressDialog\0closeParent\0\0appendPoint\0"
    "x\0y\0simulationComplete\0GwentSimResults\0"
    "r\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgressDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   35,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       9,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void ProgressDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProgressDialog *_t = static_cast<ProgressDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeParent(); break;
        case 1: _t->appendPoint((*reinterpret_cast< const qreal(*)>(_a[1])),(*reinterpret_cast< const qreal(*)>(_a[2]))); break;
        case 2: _t->simulationComplete((*reinterpret_cast< const GwentSimResults(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            using _t = void (ProgressDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressDialog::closeParent)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProgressDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ProgressDialog.data,
      qt_meta_data_ProgressDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProgressDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgressDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgressDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ProgressDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ProgressDialog::closeParent()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
