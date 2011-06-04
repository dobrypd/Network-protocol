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
