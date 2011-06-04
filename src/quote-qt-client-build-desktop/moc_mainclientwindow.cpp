/****************************************************************************
** Meta object code from reading C++ file 'mainclientwindow.h'
**
** Created: Tue May 24 23:14:32 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../quote-qt-client/mainclientwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainclientwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainClientWindow[] = {

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
      18,   17,   17,   17, 0x08,
      34,   17,   17,   17, 0x08,
      52,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainClientWindow[] = {
    "MainClientWindow\0\0btnNewPressed()\0"
    "btnAboutPressed()\0addrChanged()\0"
};

const QMetaObject MainClientWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainClientWindow,
      qt_meta_data_MainClientWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainClientWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainClientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainClientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainClientWindow))
        return static_cast<void*>(const_cast< MainClientWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainClientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: btnNewPressed(); break;
        case 1: btnAboutPressed(); break;
        case 2: addrChanged(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
