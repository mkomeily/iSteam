/****************************************************************************
** Meta object code from reading C++ file 'calcform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calcform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calcform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calcForm_t {
    QByteArrayData data[21];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calcForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calcForm_t qt_meta_stringdata_calcForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "calcForm"
QT_MOC_LITERAL(1, 9, 14), // "sendDataSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "ThermoState"
QT_MOC_LITERAL(4, 37, 5), // "state"
QT_MOC_LITERAL(5, 43, 8), // "FormLoad"
QT_MOC_LITERAL(6, 52, 9), // "ClearForm"
QT_MOC_LITERAL(7, 62, 7), // "CloseMe"
QT_MOC_LITERAL(8, 70, 9), // "Calculate"
QT_MOC_LITERAL(9, 80, 11), // "ModeChanged"
QT_MOC_LITERAL(10, 92, 11), // "UnitChanged"
QT_MOC_LITERAL(11, 104, 15), // "SetUnit_Nothing"
QT_MOC_LITERAL(12, 120, 10), // "SetUnit_pT"
QT_MOC_LITERAL(13, 131, 10), // "SetUnit_ph"
QT_MOC_LITERAL(14, 142, 10), // "SetUnit_ps"
QT_MOC_LITERAL(15, 153, 10), // "SetUnit_hs"
QT_MOC_LITERAL(16, 164, 12), // "SetUnit_RhoT"
QT_MOC_LITERAL(17, 177, 13), // "SetUnit_p_Sat"
QT_MOC_LITERAL(18, 191, 13), // "SetUnit_T_Sat"
QT_MOC_LITERAL(19, 205, 9), // "SetUnit_h"
QT_MOC_LITERAL(20, 215, 15) // "recieveDataSlot"

    },
    "calcForm\0sendDataSignal\0\0ThermoState\0"
    "state\0FormLoad\0ClearForm\0CloseMe\0"
    "Calculate\0ModeChanged\0UnitChanged\0"
    "SetUnit_Nothing\0SetUnit_pT\0SetUnit_ph\0"
    "SetUnit_ps\0SetUnit_hs\0SetUnit_RhoT\0"
    "SetUnit_p_Sat\0SetUnit_T_Sat\0SetUnit_h\0"
    "recieveDataSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calcForm[] = {

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

void calcForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calcForm *_t = static_cast<calcForm *>(_o);
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
        case 8: _t->SetUnit_pT(); break;
        case 9: _t->SetUnit_ph(); break;
        case 10: _t->SetUnit_ps(); break;
        case 11: _t->SetUnit_hs(); break;
        case 12: _t->SetUnit_RhoT(); break;
        case 13: _t->SetUnit_p_Sat(); break;
        case 14: _t->SetUnit_T_Sat(); break;
        case 15: _t->SetUnit_h(); break;
        case 16: _t->recieveDataSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calcForm::*_t)(ThermoState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calcForm::sendDataSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject calcForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_calcForm.data,
      qt_meta_data_calcForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *calcForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calcForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_calcForm.stringdata0))
        return static_cast<void*>(const_cast< calcForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int calcForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void calcForm::sendDataSignal(ThermoState _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
