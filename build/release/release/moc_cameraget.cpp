/****************************************************************************
** Meta object code from reading C++ file 'cameraget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Major3/cameraget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameraget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraGet_t {
    QByteArrayData data[13];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraGet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraGet_t qt_meta_stringdata_CameraGet = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CameraGet"
QT_MOC_LITERAL(1, 10, 4), // "back"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "getFace"
QT_MOC_LITERAL(4, 24, 7), // "cv::Mat"
QT_MOC_LITERAL(5, 32, 9), // "confirmed"
QT_MOC_LITERAL(6, 42, 7), // "refused"
QT_MOC_LITERAL(7, 50, 6), // "camera"
QT_MOC_LITERAL(8, 57, 5), // "start"
QT_MOC_LITERAL(9, 63, 15), // "on_back_clicked"
QT_MOC_LITERAL(10, 79, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(11, 97, 9), // "getCamera"
QT_MOC_LITERAL(12, 107, 5) // "match"

    },
    "CameraGet\0back\0\0getFace\0cv::Mat\0"
    "confirmed\0refused\0camera\0start\0"
    "on_back_clicked\0on_cancel_clicked\0"
    "getCamera\0match"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraGet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,
       7,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   79,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CameraGet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraGet *_t = static_cast<CameraGet *>(_o);
        switch (_id) {
        case 0: _t->back((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getFace((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->confirmed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->refused((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->camera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->start((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->on_back_clicked(); break;
        case 7: _t->on_cancel_clicked(); break;
        case 8: _t->getCamera(); break;
        case 9: _t->match(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraGet::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraGet::back)) {
                *result = 0;
            }
        }
        {
            typedef void (CameraGet::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraGet::getFace)) {
                *result = 1;
            }
        }
        {
            typedef void (CameraGet::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraGet::confirmed)) {
                *result = 2;
            }
        }
        {
            typedef void (CameraGet::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraGet::refused)) {
                *result = 3;
            }
        }
        {
            typedef void (CameraGet::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraGet::camera)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject CameraGet::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CameraGet.data,
      qt_meta_data_CameraGet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraGet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraGet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraGet.stringdata))
        return static_cast<void*>(const_cast< CameraGet*>(this));
    return QDialog::qt_metacast(_clname);
}

int CameraGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CameraGet::back(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraGet::getFace(cv::Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CameraGet::confirmed(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CameraGet::refused(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CameraGet::camera(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
