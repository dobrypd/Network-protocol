#include "server.h"

Server::Server(QSqlTableModel *model, int port, Log* log): model(model), port(port), log(log)
{
    //startuję serwer
    log->addLog("Serwer startuje");
}

Server::~Server()
{
    //kończę pracę
    log->addLog("Serwer konczy dzialanie");
}

QString Server::readQuotation()
{
    log->addLog("rozpoczynam procedure readQuotation CITE_REQUEST_MSG(key) : MSG_T ");

    log->addLog("koncze procedure readQuotation");
}

void Server::initSocket()
{
    log->addLog("rozpoczynam initSocket");

    log->addLog("koncze initSocket");
}

void Server::readPendingDatagrams()
{
    log->addLog("rozpoczynam readPendingDatagrams");

    log->addLog("koncze readPendingDatagrams");
}

void Server::sendQuotation(QHostAddress& host, QString& quot)
{
    log->addLog("rozpoczynam sendQuotation dla hosta:" + "i cytatu" + quot);

    log->addLog("koncze sendQuotation dla hosta:")
}

void Server::sendErrno(QHostAddress& host, quint8 errno)
{
    log->addLog("rozpoczynam sendErrno dla hosta:" + "i errno:" + errno);

    log->addLog("koncze sendErrno dla hosta:");
}
