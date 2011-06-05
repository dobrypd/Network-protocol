#include "server.h"

#include <QtNetwork>

Server::Server(QMainWindow *wnd, QSqlTableModel *model, int port, Log* log):
    wnd(wnd), model(model), port(port), log(log)
{
    //startuję serwer
    log->addLog("Serwer startuje");
    initSocket();
}

Server::~Server()
{
    //kończę pracę
    log->addLog("Serwer konczy dzialanie");
    delete udpSocket;
}

QString* Server::readQuotation()
{
    log->addLog("rozpoczynam procedure readQuotation CITE_REQUEST_MSG(key) : MSG_T ");
    QString* quote = new QString("to jest test");
    log->addLog(QString("koncze procedure readQuotation wyrzucam cytat: '").append(quote));
    return quote;
}

void Server::initSocket()
{
    log->addLog("rozpoczynam initSocket");

    udpSocket = new QUdpSocket(wnd);
    udpSocket->bind(QHostAddress::LocalHost, this->port);

    log->addLog("Lacze sygnal ze slotem - rozpoczynam nasluchiwanie");
    wnd->connect(udpSocket, SIGNAL(readyRead()),
                 wnd, SLOT(readPendingDatagrams()));

    log->addLog("koncze initSocket");
}

void Server::readPendingDatagrams()
{
    log->addLog("rozpoczynam readPendingDatagrams");

    while (udpSocket->hasPendingDatagrams()) {
        log->addLog("pobieram dane z gniazda");

        MSG_T requestMsg;
        quint64 requestMsgSize = sizeof(MSG_T);
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram((char*)&requestMsg, requestMsgSize,
                                &sender, &senderPort);

        //zmieniam stan na SEND_PART_STATE
        sendQuotation(requestMsg, sender, senderPort);
    }

    log->addLog("koncze readPendingDatagrams");
}

void Server::sendQuotation(MSG_T request, QHostAddress& host, quint16 port)
{
    log->addLog("rozpoczynam sendQuotation dla hosta: "
                + host.toString()
                + ":"
                + QString::number(port));

    QString *quot = readQuotation();
    if (quot == NULL){
        sendErrno(request, ENODATA, host, port);
        return;
    }

    /*wysylaj czesci*/
    while (quot->size() > 0){
        quot->clear();
    }
    delete quot;

    log->addLog("koncze sendQuotation dla hosta: "
                + host.toString()
                + ":"
                + QString::number(port));
}

void Server::sendErrno(MSG_T request, quint8 errno, QHostAddress& host, quint16 port)
{
    log->addLog("rozpoczynam sendErrno dla hosta: "
                + host.toString()
                + ":"
                + QString::number(port)
                + ", errno:"
                + QString::number(errno));

    log->addLog("koncze sendErrno dla hosta:");
}
