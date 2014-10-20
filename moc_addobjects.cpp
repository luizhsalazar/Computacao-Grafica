/****************************************************************************
** Meta object code from reading C++ file 'addobjects.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addobjects.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addobjects.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddObjects_t {
    QByteArrayData data[11];
    char stringdata[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddObjects_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddObjects_t qt_meta_stringdata_AddObjects = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 24),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 21),
QT_MOC_LITERAL(4, 59, 28),
QT_MOC_LITERAL(5, 88, 25),
QT_MOC_LITERAL(6, 114, 22),
QT_MOC_LITERAL(7, 137, 25),
QT_MOC_LITERAL(8, 163, 26),
QT_MOC_LITERAL(9, 190, 28),
QT_MOC_LITERAL(10, 219, 26)
    },
    "AddObjects\0on_deleteEdgePol_clicked\0"
    "\0on_addEdgePol_clicked\0"
    "on_pushButtonPolygon_clicked\0"
    "on_deleteCoordPol_clicked\0"
    "on_addCoordPol_clicked\0on_pushButtonLine_clicked\0"
    "on_pushButtonPoint_clicked\0"
    "on_selectColorButton_clicked\0"
    "on_addObjectCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddObjects[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void AddObjects::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddObjects *_t = static_cast<AddObjects *>(_o);
        switch (_id) {
        case 0: _t->on_deleteEdgePol_clicked(); break;
        case 1: _t->on_addEdgePol_clicked(); break;
        case 2: _t->on_pushButtonPolygon_clicked(); break;
        case 3: _t->on_deleteCoordPol_clicked(); break;
        case 4: _t->on_addCoordPol_clicked(); break;
        case 5: _t->on_pushButtonLine_clicked(); break;
        case 6: _t->on_pushButtonPoint_clicked(); break;
        case 7: _t->on_selectColorButton_clicked(); break;
        case 8: _t->on_addObjectCancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AddObjects::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddObjects.data,
      qt_meta_data_AddObjects,  qt_static_metacall, 0, 0}
};


const QMetaObject *AddObjects::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddObjects::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddObjects.stringdata))
        return static_cast<void*>(const_cast< AddObjects*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddObjects::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
