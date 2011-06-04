#ifndef SERVER_H
#define SERVER_H

#include "db.h"
#include "utils.h"
#include "protocolconsts.h"

#include <QtNetwork/QUdpSocket>
#include <QString>

class Server
{
public:
    Server(QSqlTableModel *model, int port, Log* log);
    ~Server();
private:
    QSqlTableModel *model; //baza z cytatami
    QUdpSocket udpSocket;
    int port;
    Log* log;

    QString readQuotation();
    void initSocket();
    //read CITE_REQUEST_MSG(key) : MSG_T
    void readPendingDatagrams();
    //send REPLY_MSG(key, index, parts, text) : CITE_MSG_T
    void sendQuotation(QHostAddress& host, QString& quot);
    //send SERVER_ERR_MSG(errno) : ERR_MSG_T
    void sendErrno(QHostAddress& host, quint8 errno);
};

#endif // SERVER_H
