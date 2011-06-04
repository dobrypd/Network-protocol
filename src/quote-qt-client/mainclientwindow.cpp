#include "mainclientwindow.h"
#include "ui_mainclientwindow.h"

MainClientWindow::MainClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainClientWindow)
{
    ui->setupUi(this);
    client = new Client(ui->edtServerAddr->text(), ui->edtPort->text().toInt());
}

MainClientWindow::~MainClientWindow()
{
    delete client;
    delete ui;
}

void MainClientWindow::btnAboutPressed()
{
    QString text = "<center>Projekt zaliczeniowy z Sieci Komputerowych. </center><br />"
            "autor: <b>Piotr Dobrowolski</b> <br/> nr albumu: <b>291528</b>";
    ui->quoteArea->setHtml(text);
    ui->progressBar->setValue(ui->progressBar->maximum());
}

void MainClientWindow::btnNewPressed()
{
    /*tutaj będą zmiany*/
    QString text = "<b>Nowy cytat</b>";
    ui->quoteArea->setHtml(text);
    ui->progressBar->setValue((ui->progressBar->value() + 1)%100);
    /*tutaj będzie obsłużone pobieranie cytatu z serwera*/
    ui->quoteArea->setHtml(client->getQuote());
}

void MainClientWindow::addrChanged(){
    delete client;
    client = new Client(ui->edtServerAddr->text(), ui->edtPort->text().toInt());
}
