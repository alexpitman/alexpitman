/****************************************************************************
** Meta object code from reading C++ file 'qgl_p.h'
**
** Created: Wed Nov 3 12:19:03 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qgl_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgl_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGLSignalProxy[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   16,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QGLSignalProxy[] = {
    "QGLSignalProxy\0\0context\0"
    "aboutToDestroyContext(const QGLContext*)\0"
};

const QMetaObject QGLSignalProxy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGLSignalProxy,
      qt_meta_data_QGLSignalProxy, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGLSignalProxy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGLSignalProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGLSignalProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGLSignalProxy))
        return static_cast<void*>(const_cast< QGLSignalProxy*>(this));
    return QObject::qt_metacast(_clname);
}

int QGLSignalProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: aboutToDestroyContext((*reinterpret_cast< const QGLContext*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QGLSignalProxy::aboutToDestroyContext(const QGLContext * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
