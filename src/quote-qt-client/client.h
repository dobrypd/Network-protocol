#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
class Client
{
public:
    Client(QString addr, int port);
    ~Client();

    QString getQuote() ;
private:
    QString addr;
    int port;
    QUdpSocket* udpSocket;

};

#endif // CLIENT_H
