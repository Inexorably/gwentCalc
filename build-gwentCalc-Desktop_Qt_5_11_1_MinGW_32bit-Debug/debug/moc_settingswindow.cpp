/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gwentCalc/settingswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsWindow_t {
    QByteArrayData data[13];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsWindow_t qt_meta_stringdata_SettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingsWindow"
QT_MOC_LITERAL(1, 15, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(4, 60, 30), // "on_nIterationsCheckBox_clicked"
QT_MOC_LITERAL(5, 91, 26), // "on_percentCheckBox_clicked"
QT_MOC_LITERAL(6, 118, 25), // "on_r1SpinBox_valueChanged"
QT_MOC_LITERAL(7, 144, 4), // "arg1"
QT_MOC_LITERAL(8, 149, 25), // "on_r2SpinBox_valueChanged"
QT_MOC_LITERAL(9, 175, 28), // "on_varyRoundCheckBox_clicked"
QT_MOC_LITERAL(10, 204, 35), // "on_bloodThirst1SpinBox_valueC..."
QT_MOC_LITERAL(11, 240, 35), // "on_bloodThirst2SpinBox_valueC..."
QT_MOC_LITERAL(12, 276, 35) // "on_bloodThirst3SpinBox_valueC..."

    },
    "SettingsWindow\0on_cancelButton_clicked\0"
    "\0on_okButton_clicked\0"
    "on_nIterationsCheckBox_clicked\0"
    "on_percentCheckBox_clicked\0"
    "on_r1SpinBox_valueChanged\0arg1\0"
    "on_r2SpinBox_valueChanged\0"
    "on_varyRoundCheckBox_clicked\0"
    "on_bloodThirst1SpinBox_valueChanged\0"
    "on_bloodThirst2SpinBox_valueChanged\0"
    "on_bloodThirst3SpinBox_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      12,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,

       0        // eod
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingsWindow *_t = static_cast<SettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cancelButton_clicked(); break;
        case 1: _t->on_okButton_clicked(); break;
        case 2: _t->on_nIterationsCheckBox_clicked(); break;
        case 3: _t->on_percentCheckBox_clicked(); break;
        case 4: _t->on_r1SpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_r2SpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_varyRoundCheckBox_clicked(); break;
        case 7: _t->on_bloodThirst1SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_bloodThirst2SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_bloodThirst3SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SettingsWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingsWindow.data,
      qt_meta_data_SettingsWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
