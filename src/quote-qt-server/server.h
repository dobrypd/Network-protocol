#ifndef SERVER_H
#define SERVER_H

#include "db.h"
#include "utils.h"
#include "protocolconsts.h"

#include <QtNetwork/QUdpSocket>
#include <QString>
#include <QMainWindow>
#include <QObject>
//serwer dziala w oparciu o sygnaly okna dlatego jest tutaj QMainWindow

class Server: public QObject
{
public:
    Server(QMainWindow* wnd, QSqlTableModel *model, int port, Log *log);
    ~Server();

    void readPendingDatagrams();
private:
    QSqlTableModel *model;  //baza z cytatami
    QMainWindow* wnd;       //okno do ktorego moge podpiac udpSocket
    QUdpSocket* udpSocket;
    int port;
    Log* log;

    QByteArray* readQuotation();
    void initSocket();
    //send REPLY_MSG(key, index, parts, text) : CITE_MSG_T
    void sendQuotation(MSG_T request, QHostAddress& host, quint16 port);
    //send SERVER_ERR_MSG(errno) : ERR_MSG_T
    void sendErrno(quint8 errno, QHostAddress& host, quint16 port);

    char* nextPart(QByteArray* quote,quint16 index, quint16& size);
    void sendPart(CITE_MSG_T& msg, QHostAddress& host, quint16 port);
};

#endif // SERVER_H
