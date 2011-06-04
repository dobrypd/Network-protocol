#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
class Client
{
public:
    Client(QString addr, int port);

    QString getQuote();
private:
    QString addr;
    int port;
};

#endif // CLIENT_H
