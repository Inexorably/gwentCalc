/****************************************************************************
** Meta object code from reading C++ file 'analysiswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gwentCalc/analysiswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysiswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnalysisWindow_t {
    QByteArrayData data[6];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnalysisWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnalysisWindow_t qt_meta_stringdata_AnalysisWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AnalysisWindow"
QT_MOC_LITERAL(1, 15, 38), // "on_actionScore_vs_Round_Lengt..."
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 47), // "on_actionScore_per_Card_vs_Ro..."
QT_MOC_LITERAL(4, 103, 28), // "on_combosTimesPlayed_changed"
QT_MOC_LITERAL(5, 132, 36) // "on_actionAverage_Combo_Value_..."

    },
    "AnalysisWindow\0on_actionScore_vs_Round_Length_changed\0"
    "\0on_actionScore_per_Card_vs_Round_Length_changed\0"
    "on_combosTimesPlayed_changed\0"
    "on_actionAverage_Combo_Value_changed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnalysisWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnalysisWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnalysisWindow *_t = static_cast<AnalysisWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionScore_vs_Round_Length_changed(); break;
        case 1: _t->on_actionScore_per_Card_vs_Round_Length_changed(); break;
        case 2: _t->on_combosTimesPlayed_changed(); break;
        case 3: _t->on_actionAverage_Combo_Value_changed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AnalysisWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AnalysisWindow.data,
      qt_meta_data_AnalysisWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AnalysisWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalysisWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnalysisWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AnalysisWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
