#include "mainserverwindow.h"
#include "ui_mainserverwindow.h"

MainServerWindow::MainServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainServerWindow)
{
    /*inicjalizuję plik logów*/
    log = new Log();
    log->addLog(UTF("Inicjalizuję"));
    /*rysuję okienko*/
    ui->setupUi(this);
    ui->btnSrvReset->setEnabled(false);
    ui->btnSrvStop->setEnabled(false);

    /*łączę z bazą danych*/
    log->addLog(UTF("Łączę się z bazą"));
    database = new DB();
    if (!(database->createConnection()))
        return;

    /*uzupelnianie bazy danych*/
    log->addLog(UTF("Pobieram dane z bazy"));
    model = new QSqlTableModel(this);
    model->setTable(TABLENAME);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("QUOTATATION"));

    ui->bdTable->setModel(model);
}

MainServerWindow::~MainServerWindow()
{
    /*zamknij serwer jeśli włączony*/
    if (ui->btnSrvStop->isEnabled())
        btnSrvStop();
    delete ui;
    delete model;
    delete database;
    delete log;
}


/*obsługa przycisków*/
void MainServerWindow::btnSrvReset()
{
    QMessageBox::information(0, ("Uwaga"),
        tr("Restart serwera"), QMessageBox::Ok);
    btnSrvStop();
    btnSrvStart();
}

void MainServerWindow::btnSrvStart()
{
    log->addLog(UTF("btn server start kliknięty"));
    QMessageBox::information(0, ("Uwaga"),
        tr("Start serwera"), QMessageBox::Ok);
    ui->btnSrvReset->setEnabled(true);
    ui->btnSrvStop->setEnabled(true);
    ui->btnSrvStart->setEnabled(false);
    ui->actionResetuj->setEnabled(true);
    ui->actionStop->setEnabled(true);
    ui->actionStart->setEnabled(false);

    int port = ui->edtPort->text().toInt();
    if ((port < 1024) || (port > 65535)) {
        port = SERVER_PORT;
        QMessageBox::warning(0, ("Uwaga"),
            UTF("Nieprawidłowy numer portu ustawiam: 44444"), QMessageBox::Ok);
        ui->edtPort->setText(QString::number(port));
    }

    server = new Server(model, port, log);
}

void MainServerWindow::btnSrvStop()
{
    log->addLog(UTF("btn server stop kliknięty"));
    QMessageBox::information(0, ("Uwaga"),
        tr("Zatrzymanie serwera"), QMessageBox::Ok);
    ui->btnSrvReset->setEnabled(false);
    ui->btnSrvStop->setEnabled(false);
    ui->btnSrvStart->setEnabled(true);
    ui->actionResetuj->setEnabled(false);
    ui->actionStop->setEnabled(false);
    ui->actionStart->setEnabled(true);

    delete server;
}

void MainServerWindow::btnAbout()
{
    QMessageBox::information(0, ("O programie"),
        UTF("Jest to praca zaliczeniowa na Sieci komputerowye\n Autor: Piotr Dobrowolski (291528)"), QMessageBox::Ok);
}

void MainServerWindow::btnAddNewQuote()
{
    log->addLog(UTF("btn new quote kliknięty"));
    if (database->addQuote(ui->quoteArea->toPlainText())){
        QMessageBox::information(0, UTF("Uwaga"),
            UTF("Dodano cytat"), QMessageBox::Ok);
        btnSubmit();
    }
}

void MainServerWindow::btnSubmit()
{
    log->addLog(UTF("Wykonuję submit"));
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, UTF("Cached Table"),
                             UTF("Błąd podczas aktualizacji: %1")
                             .arg(model->lastError().text()));
    }
}

void MainServerWindow::btnResetDB(){
    log->addLog(UTF("Resetuję bazę"));
    if (database->createTable()){
        QMessageBox::information(0, ("Uwaga"),
            UTF("Baza została stworzona na nowo"), QMessageBox::Ok);
    }
    btnSubmit();
}

void MainServerWindow::btnDel(){
    log->addLog(UTF("Usuwam"));
    QModelIndex index;
    foreach(index, (ui->bdTable->selectionModel())->selectedRows())
        model->removeRow(index.row());

    QMessageBox::information(0, UTF("Uwaga"), UTF("Usunięto"), QMessageBox::Ok);
    btnSubmit();
}

void MainServerWindow::btnOpenLogFile(){
    QDesktopServices::openUrl(Log::LOGFILENAME());
}
