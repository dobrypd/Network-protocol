#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QMainWindow>
#include <exception>
#include <QtNetwork>
#include <QtNetwork/QUdpSocket>
#include <boost/function.hpp>

#include "protocolconsts.h"
#include "rand64.h"

typedef boost::function<void(int pr)> progressSetT;

class Client : public QObject
{
public:
    Client(QString addr, int port);
    ~Client();

    QString getQuote(progressSetT prSet) throw(errnoException&);
private:
    QHostAddress addr;
    quint16 port;
    QUdpSocket* udpSocket;
    rand64 r;

    void initSocket();
    void downloadParts(QByteArray** qparts,quint16& parts, quint64& quoteID, progressSetT prSet) throw(errnoException&);
    quint8 getNext(QByteArray& current, quint16& index, quint16& parts, quint64& quoteID);
    CITE_MSG_T* cite_msgFromStream(QDataStream& stream);
};

#endif // CLIENT_H
