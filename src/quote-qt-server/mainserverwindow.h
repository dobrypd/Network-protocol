#ifndef MAINSERVERWINDOW_H
#define MAINSERVERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopServices>
#include "db.h"
#include "utils.h"
#include "server.h"


namespace Ui {
    class MainServerWindow;
}

class MainServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainServerWindow(QWidget *parent = 0);
    ~MainServerWindow();

private slots:
    void btnSrvReset();
    void btnSrvStart();
    void btnSrvStop();
    void btnAbout();
    void btnAddNewQuote();
    void btnSubmit();
    void btnResetDB();
    void btnDel();
    void btnOpenLogFile();

private:
    Ui::MainServerWindow *ui;
    QSqlTableModel *model;
    DB *database;
    Server *server;
    Log* log;

};

#endif // MAINSERVERWINDOW_H
