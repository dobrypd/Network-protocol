#include "db.h"

DB::DB() { }

DB::~DB() { }

bool DB::createConnection()
{
    data = QSqlDatabase::addDatabase("QSQLITE");
    data.setHostName("localhost");
    data.setDatabaseName(DBNAME);
    if (!data.open()) {
        QMessageBox::critical(0, UTF("Nie można otworzyć bazy!"),
            UTF("Broblemy z otworzeniem bazy danych!"), QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool DB::createTable(){
    /*resetuję bazę*/
    QMessageBox msgB;
    msgB.addButton(QMessageBox::Ok);
    msgB.addButton(QMessageBox::Cancel);
    msgB.setText(UTF("Czy na pewno chcesz zresetować bazę danych?"));
    int ret = msgB.exec();
    if (ret != QMessageBox::Ok){
        return false;
    }

    QSqlQuery query;
    query.exec("DROP TABLE quotes");
    query.exec("CREATE TABLE quotes (id int primary key, "
               "quotation TEXT)");
    query.exec("INSERT INTO quotes VALUES(101, 'Jakis pierwszy cytat.')");
    query.exec("INSERT INTO quotes VALUES(102, 'Jakis drugi cytat.')");
    query.exec("INSERT INTO quotes VALUES(103, 'Jakis trzeci cytat.')");
    query.exec("INSERT INTO quotes VALUES(104, 'Jakis czwarty cytat.')");
    query.exec("INSERT INTO quotes VALUES(105, 'Jakis piaty cytat.')");
    query.exec(UTF("INSERT INTO quotes VALUES(106, 'Jakis szósty cytat.')"));
    query.exec("INSERT INTO quotes VALUES(107, 'Jakis siódmy cytat.')");
    query.exec("INSERT INTO quotes VALUES(108, 'Jakis ósmy cytat.')");
    query.exec("INSERT INTO quotes VALUES(109, 'Jakis dziewiaty cytat.')");
    query.exec("INSERT INTO quotes VALUES(111, 'Jakis dziesiaty cytat.')");

    return true;
}

bool DB::addQuote(QString text)
{
    QSqlQuery query;
    QString sql = "INSERT INTO quotes VALUES((SELECT MAX(id)+1 FROM quotes), '";
    sql.append(text);
    sql.append("')");
    query.exec(sql);
    return true;
}
