#include <QtGui/QApplication>
#include "mainserverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainServerWindow w;
    w.show();

    return a.exec();
}
