#ifndef MAINCLIENTWINDOW_H
#define MAINCLIENTWINDOW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
    class MainClientWindow;
}

class MainClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainClientWindow(QWidget *parent = 0);
    ~MainClientWindow();

private slots:
    void btnNewPressed();
    void btnAboutPressed();
    void addrChanged();


private:
    Ui::MainClientWindow *ui;
    Client *client;
};

#endif // MAINCLIENTWINDOW_H
