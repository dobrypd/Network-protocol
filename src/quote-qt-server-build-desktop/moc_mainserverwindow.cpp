/****************************************************************************
** Meta object code from reading C++ file 'mainserverwindow.h'
**
** Created: Tue May 24 21:21:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../quote-qt-server/mainserverwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainserverwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainServerWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      32,   17,   17,   17, 0x08,
      46,   17,   17,   17, 0x08,
      59,   17,   17,   17, 0x08,
      70,   17,   17,   17, 0x08,
      87,   17,   17,   17, 0x08,
      99,   17,   17,   17, 0x08,
     112,   17,   17,   17, 0x08,
     121,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainServerWindow[] = {
    "MainServerWindow\0\0btnSrvReset()\0"
    "btnSrvStart()\0btnSrvStop()\0btnAbout()\0"
    "btnAddNewQuote()\0btnSubmit()\0btnResetDB()\0"
    "btnDel()\0btnOpenLogFile()\0"
};

const QMetaObject MainServerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainServerWindow,
      qt_meta_data_MainServerWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainServerWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainServerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainServerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainServerWindow))
        return static_cast<void*>(const_cast< MainServerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainServerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: btnSrvReset(); break;
        case 1: btnSrvStart(); break;
        case 2: btnSrvStop(); break;
        case 3: btnAbout(); break;
        case 4: btnAddNewQuote(); break;
        case 5: btnSubmit(); break;
        case 6: btnResetDB(); break;
        case 7: btnDel(); break;
        case 8: btnOpenLogFile(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
