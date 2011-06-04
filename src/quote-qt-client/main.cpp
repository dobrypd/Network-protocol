#include <QtGui/QApplication>
#include "mainclientwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainClientWindow w;
    w.show();

    return a.exec();
}
