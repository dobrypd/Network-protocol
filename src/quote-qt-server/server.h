#ifndef SERVER_H
#define SERVER_H

#include "db.h"
#include "utils.h"
#include "protocolconsts.h"

#include <QtNetwork/QUdpSocket>
#include <QString>
#include <QMainWindow>
//serwer dziala w oparciu o sygnaly okna dlatego jest tutaj QMainWindow

class Server
{
public:
    Server(QMainWindow *wnd, QSqlTableModel *model, int port, Log *log);

    //public bo bedzie slotem polaczonym z sygnalem dotarcia
    //read CITE_REQUEST_MSG(key) : MSG_T
    void readPendingDatagrams();


    ~Server();
private:
    QMainWindow *wnd;
    QSqlTableModel *model; //baza z cytatami
    QUdpSocket* udpSocket;
    int port;
    Log* log;

    QString* readQuotation();
    void initSocket();

    //send REPLY_MSG(key, index, parts, text) : CITE_MSG_T
    void sendQuotation(MSG_T request, QHostAddress& host, quint16 port);
    //send SERVER_ERR_MSG(errno) : ERR_MSG_T
    void sendErrno(MSG_T request, quint8 errno, QHostAddress& host, quint16 port);
};

#endif // SERVER_H
