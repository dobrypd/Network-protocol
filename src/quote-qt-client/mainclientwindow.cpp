#include "mainclientwindow.h"
#include "ui_mainclientwindow.h"

#include <boost/bind.hpp>
#include <boost/function.hpp>

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

void progressSetter(QProgressBar* prBar, int pr)
{
    prBar->setValue(pr);
}

void MainClientWindow::btnNewPressed()
{
    ui->quoteArea->setHtml(UTF("<p style=\"color=green;font-size=larger;\"><Ładowanie.../p>"));
    QString q = UTF("Pusty cytat");
    try
    {
        q = client->getQuote(boost::bind(progressSetter, ui->progressBar, _1));

    }
    catch (errnoException& e)
    {
        ui->quoteArea->setHtml("<p style=\"color:red;\">" + e.to_str() + "</p>");
        ui->progressBar->setValue(ui->progressBar->minimum());
        return ;
    }

    ui->quoteArea->setHtml(q);
}

void MainClientWindow::addrChanged(){
    delete client;
    client = new Client(ui->edtServerAddr->text(), ui->edtPort->text().toInt());
}
