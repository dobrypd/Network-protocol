/********************************************************************************
** Form generated from reading UI file 'mainserverwindow.ui'
**
** Created: Tue May 24 20:28:47 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSERVERWINDOW_H
#define UI_MAINSERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainServerWindow
{
public:
    QAction *actionResetuj;
    QAction *actionStop;
    QAction *actionStart;
    QAction *action_Zako_cz;
    QAction *actionO_programie;
    QAction *actionResetuj_baz_danych;
    QAction *actionOtw_rz_plik_log_w_serwera;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *edtPort;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QPushButton *btnSrvReset;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSrvStop;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSrvStart;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *quoteArea;
    QPushButton *btnBDAdd;
    QFrame *line;
    QTableView *bdTable;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDel;
    QPushButton *btnBDSubmit;
    QMenuBar *menuBar;
    QMenu *menu_Serwer;
    QMenu *menu_Pomoc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainServerWindow)
    {
        if (MainServerWindow->objectName().isEmpty())
            MainServerWindow->setObjectName(QString::fromUtf8("MainServerWindow"));
        MainServerWindow->resize(671, 494);
        actionResetuj = new QAction(MainServerWindow);
        actionResetuj->setObjectName(QString::fromUtf8("actionResetuj"));
        actionResetuj->setEnabled(false);
        actionStop = new QAction(MainServerWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionStop->setEnabled(false);
        actionStart = new QAction(MainServerWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        action_Zako_cz = new QAction(MainServerWindow);
        action_Zako_cz->setObjectName(QString::fromUtf8("action_Zako_cz"));
        actionO_programie = new QAction(MainServerWindow);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        actionResetuj_baz_danych = new QAction(MainServerWindow);
        actionResetuj_baz_danych->setObjectName(QString::fromUtf8("actionResetuj_baz_danych"));
        actionOtw_rz_plik_log_w_serwera = new QAction(MainServerWindow);
        actionOtw_rz_plik_log_w_serwera->setObjectName(QString::fromUtf8("actionOtw_rz_plik_log_w_serwera"));
        centralWidget = new QWidget(MainServerWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(16777215, 100));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        edtPort = new QLineEdit(groupBox);
        edtPort->setObjectName(QString::fromUtf8("edtPort"));

        horizontalLayout->addWidget(edtPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        btnSrvReset = new QPushButton(groupBox);
        btnSrvReset->setObjectName(QString::fromUtf8("btnSrvReset"));
        btnSrvReset->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnSrvReset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnSrvStop = new QPushButton(groupBox);
        btnSrvStop->setObjectName(QString::fromUtf8("btnSrvStop"));
        btnSrvStop->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnSrvStop);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnSrvStart = new QPushButton(groupBox);
        btnSrvStart->setObjectName(QString::fromUtf8("btnSrvStart"));
        btnSrvStart->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnSrvStart);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        quoteArea = new QTextEdit(groupBox_2);
        quoteArea->setObjectName(QString::fromUtf8("quoteArea"));
        quoteArea->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(quoteArea);

        btnBDAdd = new QPushButton(groupBox_2);
        btnBDAdd->setObjectName(QString::fromUtf8("btnBDAdd"));

        horizontalLayout_2->addWidget(btnBDAdd);


        verticalLayout_4->addLayout(horizontalLayout_2);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        bdTable = new QTableView(groupBox_2);
        bdTable->setObjectName(QString::fromUtf8("bdTable"));
        bdTable->setAlternatingRowColors(true);
        bdTable->horizontalHeader()->setDefaultSectionSize(100);
        bdTable->horizontalHeader()->setMinimumSectionSize(50);
        bdTable->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_4->addWidget(bdTable);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btnDel = new QPushButton(groupBox_2);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));

        horizontalLayout_3->addWidget(btnDel);

        btnBDSubmit = new QPushButton(groupBox_2);
        btnBDSubmit->setObjectName(QString::fromUtf8("btnBDSubmit"));

        horizontalLayout_3->addWidget(btnBDSubmit);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(verticalLayout);

        MainServerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainServerWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 21));
        menu_Serwer = new QMenu(menuBar);
        menu_Serwer->setObjectName(QString::fromUtf8("menu_Serwer"));
        menu_Pomoc = new QMenu(menuBar);
        menu_Pomoc->setObjectName(QString::fromUtf8("menu_Pomoc"));
        MainServerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainServerWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainServerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainServerWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainServerWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(btnSrvStart, btnSrvStop);
        QWidget::setTabOrder(btnSrvStop, edtPort);
        QWidget::setTabOrder(edtPort, btnSrvReset);
        QWidget::setTabOrder(btnSrvReset, quoteArea);
        QWidget::setTabOrder(quoteArea, btnBDAdd);
        QWidget::setTabOrder(btnBDAdd, bdTable);
        QWidget::setTabOrder(bdTable, btnBDSubmit);
        QWidget::setTabOrder(btnBDSubmit, btnDel);

        menuBar->addAction(menu_Serwer->menuAction());
        menuBar->addAction(menu_Pomoc->menuAction());
        menu_Serwer->addAction(actionResetuj);
        menu_Serwer->addAction(actionStop);
        menu_Serwer->addAction(actionStart);
        menu_Serwer->addSeparator();
        menu_Serwer->addAction(actionOtw_rz_plik_log_w_serwera);
        menu_Serwer->addSeparator();
        menu_Serwer->addAction(action_Zako_cz);
        menu_Pomoc->addAction(actionO_programie);
        menu_Pomoc->addSeparator();
        menu_Pomoc->addAction(actionResetuj_baz_danych);

        retranslateUi(MainServerWindow);
        QObject::connect(action_Zako_cz, SIGNAL(activated()), MainServerWindow, SLOT(close()));
        QObject::connect(btnSrvReset, SIGNAL(clicked()), MainServerWindow, SLOT(btnSrvReset()));
        QObject::connect(btnSrvStop, SIGNAL(clicked()), MainServerWindow, SLOT(btnSrvStop()));
        QObject::connect(btnSrvStart, SIGNAL(clicked()), MainServerWindow, SLOT(btnSrvStart()));
        QObject::connect(btnBDAdd, SIGNAL(clicked()), MainServerWindow, SLOT(btnAddNewQuote()));
        QObject::connect(btnBDSubmit, SIGNAL(clicked()), MainServerWindow, SLOT(btnSubmit()));
        QObject::connect(actionO_programie, SIGNAL(activated()), MainServerWindow, SLOT(btnAbout()));
        QObject::connect(actionResetuj, SIGNAL(activated()), MainServerWindow, SLOT(btnSrvReset()));
        QObject::connect(actionStart, SIGNAL(activated()), MainServerWindow, SLOT(btnSrvStart()));
        QObject::connect(actionStop, SIGNAL(activated()), MainServerWindow, SLOT(btnSrvStop()));
        QObject::connect(actionResetuj_baz_danych, SIGNAL(activated()), MainServerWindow, SLOT(btnResetDB()));
        QObject::connect(btnDel, SIGNAL(clicked()), MainServerWindow, SLOT(btnDel()));
        QObject::connect(actionOtw_rz_plik_log_w_serwera, SIGNAL(activated()), MainServerWindow, SLOT(btnOpenLogFile()));

        QMetaObject::connectSlotsByName(MainServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainServerWindow)
    {
        MainServerWindow->setWindowTitle(QApplication::translate("MainServerWindow", "Serwer", 0, QApplication::UnicodeUTF8));
        actionResetuj->setText(QApplication::translate("MainServerWindow", "Resetuj", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainServerWindow", "Stop", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("MainServerWindow", "Start", 0, QApplication::UnicodeUTF8));
        actionStart->setShortcut(QApplication::translate("MainServerWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        action_Zako_cz->setText(QApplication::translate("MainServerWindow", "&Zako\305\204cz", 0, QApplication::UnicodeUTF8));
        actionO_programie->setText(QApplication::translate("MainServerWindow", "O programie", 0, QApplication::UnicodeUTF8));
        actionResetuj_baz_danych->setText(QApplication::translate("MainServerWindow", "Resetuj baz\304\231 danych", 0, QApplication::UnicodeUTF8));
        actionOtw_rz_plik_log_w_serwera->setText(QApplication::translate("MainServerWindow", "Otw\303\263rz plik log\303\263w serwera", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainServerWindow", "Zarz\304\205dzaj serwerem", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainServerWindow", "Port:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        edtPort->setToolTip(QApplication::translate("MainServerWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Liczba z zakresu <span style=\" font-weight:600;\">&lt;1024,</span> <span style=\" font-weight:600;\">65535&gt;</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        edtPort->setInputMask(QApplication::translate("MainServerWindow", "99999; ", 0, QApplication::UnicodeUTF8));
        edtPort->setText(QApplication::translate("MainServerWindow", "44444", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainServerWindow", "Dzia\305\202ania:", 0, QApplication::UnicodeUTF8));
        btnSrvReset->setText(QApplication::translate("MainServerWindow", "Resetuj", 0, QApplication::UnicodeUTF8));
        btnSrvStop->setText(QApplication::translate("MainServerWindow", "Stop", 0, QApplication::UnicodeUTF8));
        btnSrvStart->setText(QApplication::translate("MainServerWindow", "Start", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainServerWindow", "Zarz\304\205dzaj baz\304\205 danych", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainServerWindow", "Dodaj cytat:", 0, QApplication::UnicodeUTF8));
        btnBDAdd->setText(QApplication::translate("MainServerWindow", "Dodaj", 0, QApplication::UnicodeUTF8));
        btnDel->setText(QApplication::translate("MainServerWindow", "Usu\305\204 zaznaczone cytat", 0, QApplication::UnicodeUTF8));
        btnBDSubmit->setText(QApplication::translate("MainServerWindow", "Zapisz", 0, QApplication::UnicodeUTF8));
        menu_Serwer->setTitle(QApplication::translate("MainServerWindow", "&Serwer", 0, QApplication::UnicodeUTF8));
        menu_Pomoc->setTitle(QApplication::translate("MainServerWindow", "&Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainServerWindow: public Ui_MainServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSERVERWINDOW_H
