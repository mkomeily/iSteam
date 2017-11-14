/****************************************************************************
** Meta object code from reading C++ file 'satcalcform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../satcalcform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'satcalcform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_satCalcForm_t {
    QByteArrayData data[21];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_satCalcForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_satCalcForm_t qt_meta_stringdata_satCalcForm = {
    {
QT_MOC_LITERAL(0, 0, 11), // "satCalcForm"
QT_MOC_LITERAL(1, 12, 14), // "sendDataSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "ThermoState"
QT_MOC_LITERAL(4, 40, 5), // "state"
QT_MOC_LITERAL(5, 46, 8), // "FormLoad"
QT_MOC_LITERAL(6, 55, 9), // "ClearForm"
QT_MOC_LITERAL(7, 65, 7), // "CloseMe"
QT_MOC_LITERAL(8, 73, 9), // "Calculate"
QT_MOC_LITERAL(9, 83, 11), // "ModeChanged"
QT_MOC_LITERAL(10, 95, 11), // "UnitChanged"
QT_MOC_LITERAL(11, 107, 15), // "SetUnit_Nothing"
QT_MOC_LITERAL(12, 123, 10), // "SetUnit_px"
QT_MOC_LITERAL(13, 134, 10), // "SetUnit_ph"
QT_MOC_LITERAL(14, 145, 10), // "SetUnit_ps"
QT_MOC_LITERAL(15, 156, 10), // "SetUnit_pv"
QT_MOC_LITERAL(16, 167, 10), // "SetUnit_Tx"
QT_MOC_LITERAL(17, 178, 10), // "SetUnit_Th"
QT_MOC_LITERAL(18, 189, 10), // "SetUnit_Ts"
QT_MOC_LITERAL(19, 200, 10), // "SetUnit_Tv"
QT_MOC_LITERAL(20, 211, 15) // "recieveDataSlot"

    },
    "satCalcForm\0sendDataSignal\0\0ThermoState\0"
    "state\0FormLoad\0ClearForm\0CloseMe\0"
    "Calculate\0ModeChanged\0UnitChanged\0"
    "SetUnit_Nothing\0SetUnit_px\0SetUnit_ph\0"
    "SetUnit_ps\0SetUnit_pv\0SetUnit_Tx\0"
    "SetUnit_Th\0SetUnit_Ts\0SetUnit_Tv\0"
    "recieveDataSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_satCalcForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  102,    2, 0x0a /* Public */,
       6,    0,  103,    2, 0x0a /* Public */,
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x0a /* Public */,
       9,    0,  106,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    0,  108,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    0,  112,    2, 0x0a /* Public */,
      16,    0,  113,    2, 0x0a /* Public */,
      17,    0,  114,    2, 0x0a /* Public */,
      18,    0,  115,    2, 0x0a /* Public */,
      19,    0,  116,    2, 0x0a /* Public */,
      20,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void satCalcForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        satCalcForm *_t = static_cast<satCalcForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataSignal((*reinterpret_cast< ThermoState(*)>(_a[1]))); break;
        case 1: _t->FormLoad(); break;
        case 2: _t->ClearForm(); break;
        case 3: _t->CloseMe(); break;
        case 4: _t->Calculate(); break;
        case 5: _t->ModeChanged(); break;
        case 6: _t->UnitChanged(); break;
        case 7: _t->SetUnit_Nothing(); break;
        case 8: _t->SetUnit_px(); break;
        case 9: _t->SetUnit_ph(); break;
        case 10: _t->SetUnit_ps(); break;
        case 11: _t->SetUnit_pv(); break;
        case 12: _t->SetUnit_Tx(); break;
        case 13: _t->SetUnit_Th(); break;
        case 14: _t->SetUnit_Ts(); break;
        case 15: _t->SetUnit_Tv(); break;
        case 16: _t->recieveDataSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (satCalcForm::*_t)(ThermoState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&satCalcForm::sendDataSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject satCalcForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_satCalcForm.data,
      qt_meta_data_satCalcForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *satCalcForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *satCalcForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_satCalcForm.stringdata0))
        return static_cast<void*>(const_cast< satCalcForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int satCalcForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void satCalcForm::sendDataSignal(ThermoState _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
