/****************************************************************************
** Meta object code from reading C++ file 'qerrormessage.h'
**
** Created: Wed Nov 3 12:02:18 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dialogs/qerrormessage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qerrormessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QErrorMessage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x0a,
      57,   44,   14,   14, 0x0a,
      91,   86,   14,   14, 0x1a,

       0        // eod
};

static const char qt_meta_stringdata_QErrorMessage[] = {
    "QErrorMessage\0\0message\0showMessage(QString)\0"
    "message,type\0showMessage(QString,QString)\0"
    "text\0message(QString)\0"
};

const QMetaObject QErrorMessage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QErrorMessage,
      qt_meta_data_QErrorMessage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QErrorMessage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QErrorMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QErrorMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QErrorMessage))
        return static_cast<void*>(const_cast< QErrorMessage*>(this));
    return QDialog::qt_metacast(_clname);
}

int QErrorMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
