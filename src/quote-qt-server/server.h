#ifndef SERVER_H
#define SERVER_H

#include "db.h"
#include "utils.h"

class Server
{
public:
    Server(QSqlTableModel *model, int port, Log* log);
    ~Server();
private:
    QSqlTableModel *model; //baza z cytatamii
    int port;
    Log* log;
};

#endif // SERVER_H
