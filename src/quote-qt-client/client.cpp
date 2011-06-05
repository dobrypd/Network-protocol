#include "client.h"
#include <QMessageBox>
/*debug*/
void msg(QString msg){
    QMessageBox::information(0, ("Uwaga"),
        msg, QMessageBox::Ok);
}
/******/

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
    prSet(0);
    MSG_T request;
    request.key = 12;
    request.msg_id = 1;
    udpSocket->writeDatagram((char*)&request, sizeof(MSG_T), addr, port);

    //throw errnoException(E_USR1);
    //udpSocket->readDatagram()

    return "";
}
