/****************************************************************************
** Meta object code from reading C++ file 'MyTcpSocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MyTcpSocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyTcpSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTcpSocket_t {
    QByteArrayData data[9];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyTcpSocket_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyTcpSocket_t qt_meta_stringdata_MyTcpSocket = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 10),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 2),
QT_MOC_LITERAL(4, 27, 7),
QT_MOC_LITERAL(5, 35, 15),
QT_MOC_LITERAL(6, 51, 12),
QT_MOC_LITERAL(7, 64, 11),
QT_MOC_LITERAL(8, 76, 14)
    },
    "MyTcpSocket\0getMessage\0\0id\0message\0"
    "disconnectedSIN\0MyTcpSocket*\0readMessage\0"
    "onDisconnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTcpSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x05,
       5,    1,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    0,   42,    2, 0x0a,
       8,    0,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyTcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTcpSocket *_t = static_cast<MyTcpSocket *>(_o);
        switch (_id) {
        case 0: _t->getMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->disconnectedSIN((*reinterpret_cast< MyTcpSocket*(*)>(_a[1]))); break;
        case 2: _t->readMessage(); break;
        case 3: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTcpSocket::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpSocket::getMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTcpSocket::*_t)(MyTcpSocket * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpSocket::disconnectedSIN)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MyTcpSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_MyTcpSocket.data,
      qt_meta_data_MyTcpSocket,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyTcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTcpSocket.stringdata))
        return static_cast<void*>(const_cast< MyTcpSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int MyTcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
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
void MyTcpSocket::getMessage(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTcpSocket::disconnectedSIN(MyTcpSocket * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
