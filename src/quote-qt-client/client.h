#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QMainWindow>
#include <exception>
#include <QtNetwork>
#include <QtNetwork/QUdpSocket>

#include <boost/function.hpp>

#include "protocolconsts.h"

typedef boost::function<void(int pr)> progressSetT;

class Client
{
public:
    Client(QMainWindow *wnd, QString addr, int port);
    ~Client();

    QString getQuote(progressSetT prSet) throw(errnoException&);
private:
    QHostAddress addr;
    quint16 port;
    QUdpSocket* udpSocket;
    QMainWindow* wnd;

    void initSocket();
};

#endif // CLIENT_H
