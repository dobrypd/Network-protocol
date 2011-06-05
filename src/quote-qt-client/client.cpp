#include "client.h"

Client::Client(QMainWindow *wnd, QString addr, int port): wnd(wnd), addr(QHostAddress(addr)), port(port)
{
    initSocket();
}

Client::~Client()
{
    delete udpSocket;
}

void Client::initSocket()
{
    udpSocket = new QUdpSocket(wnd);
    udpSocket->bind(QHostAddress::LocalHost);
}


QString Client::getQuote(progressSetT prSet) throw(errnoException&)
{
    //wyslij prosbe
    //odbieraj
    prSet(0);

    throw errnoException(E_USR1);

    return "";
}
