/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "sendDataSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "ThermoState"
QT_MOC_LITERAL(4, 39, 5), // "state"
QT_MOC_LITERAL(5, 45, 15), // "recieveDataSlot"
QT_MOC_LITERAL(6, 61, 11), // "exitAppSlot"
QT_MOC_LITERAL(7, 73, 12), // "calcFormSlot"
QT_MOC_LITERAL(8, 86, 15), // "satCalcFormSlot"
QT_MOC_LITERAL(9, 102, 14), // "plotpTFormSlot"
QT_MOC_LITERAL(10, 117, 26), // "createCalcFormMdiChildForm"
QT_MOC_LITERAL(11, 144, 9), // "calcForm*"
QT_MOC_LITERAL(12, 154, 29), // "createSatCalcFormMdiChildForm"
QT_MOC_LITERAL(13, 184, 12), // "satCalcForm*"
QT_MOC_LITERAL(14, 197, 28), // "createPlotpTFormMdiChildForm"
QT_MOC_LITERAL(15, 226, 11) // "plotpTForm*"

    },
    "MainWindow\0sendDataSignal\0\0ThermoState\0"
    "state\0recieveDataSlot\0exitAppSlot\0"
    "calcFormSlot\0satCalcFormSlot\0"
    "plotpTFormSlot\0createCalcFormMdiChildForm\0"
    "calcForm*\0createSatCalcFormMdiChildForm\0"
    "satCalcForm*\0createPlotpTFormMdiChildForm\0"
    "plotpTForm*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   62,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      14,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 11,
    0x80000000 | 13,
    0x80000000 | 15,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataSignal((*reinterpret_cast< ThermoState(*)>(_a[1]))); break;
        case 1: _t->recieveDataSlot((*reinterpret_cast< ThermoState(*)>(_a[1]))); break;
        case 2: _t->exitAppSlot(); break;
        case 3: _t->calcFormSlot(); break;
        case 4: _t->satCalcFormSlot(); break;
        case 5: _t->plotpTFormSlot(); break;
        case 6: { calcForm* _r = _t->createCalcFormMdiChildForm();
            if (_a[0]) *reinterpret_cast< calcForm**>(_a[0]) = _r; }  break;
        case 7: { satCalcForm* _r = _t->createSatCalcFormMdiChildForm();
            if (_a[0]) *reinterpret_cast< satCalcForm**>(_a[0]) = _r; }  break;
        case 8: { plotpTForm* _r = _t->createPlotpTFormMdiChildForm();
            if (_a[0]) *reinterpret_cast< plotpTForm**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(ThermoState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendDataSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::sendDataSignal(ThermoState _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
