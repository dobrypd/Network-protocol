#ifndef DB_H
#define DB_H

#include <QString>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include "utils.h"


/*constants*/
const QString DBNAME = "db.sqlite3";
const QString TABLENAME = "quotes";

class DB
{
public:
    DB();
    ~DB();

    bool createConnection();
    bool addQuote(QString text);

    bool createTable();
private:
    QSqlDatabase data;
};

#endif // DB_H
