/********************************************************************************
** Form generated from reading UI file 'mainclientwindow.ui'
**
** Created: Tue May 24 23:13:09 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCLIENTWINDOW_H
#define UI_MAINCLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainClientWindow
{
public:
    QAction *actionNewQuote;
    QAction *actionQuit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *edtServerAddr;
    QLabel *label_2;
    QLineEdit *edtPort;
    QSpacerItem *horizontalSpacer_6;
    QTextBrowser *quoteArea;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNew;
    QSpacerItem *horizontalSpacer_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainClientWindow)
    {
        if (MainClientWindow->objectName().isEmpty())
            MainClientWindow->setObjectName(QString::fromUtf8("MainClientWindow"));
        MainClientWindow->resize(554, 357);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainClientWindow->sizePolicy().hasHeightForWidth());
        MainClientWindow->setSizePolicy(sizePolicy);
        actionNewQuote = new QAction(MainClientWindow);
        actionNewQuote->setObjectName(QString::fromUtf8("actionNewQuote"));
        actionQuit = new QAction(MainClientWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(MainClientWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainClientWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        edtServerAddr = new QLineEdit(centralWidget);
        edtServerAddr->setObjectName(QString::fromUtf8("edtServerAddr"));
        edtServerAddr->setMinimumSize(QSize(300, 0));

        horizontalLayout_5->addWidget(edtServerAddr);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        edtPort = new QLineEdit(centralWidget);
        edtPort->setObjectName(QString::fromUtf8("edtPort"));
        edtPort->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(edtPort);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_5);

        quoteArea = new QTextBrowser(centralWidget);
        quoteArea->setObjectName(QString::fromUtf8("quoteArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(quoteArea->sizePolicy().hasHeightForWidth());
        quoteArea->setSizePolicy(sizePolicy1);
        quoteArea->setAcceptDrops(false);

        verticalLayout->addWidget(quoteArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnNew = new QPushButton(centralWidget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        horizontalLayout->addWidget(btnNew);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        MainClientWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainClientWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainClientWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainClientWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainClientWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionNewQuote);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbout);
        mainToolBar->addAction(actionQuit);

        retranslateUi(MainClientWindow);
        QObject::connect(btnNew, SIGNAL(clicked()), MainClientWindow, SLOT(btnNewPressed()));
        QObject::connect(actionNewQuote, SIGNAL(activated()), MainClientWindow, SLOT(btnNewPressed()));
        QObject::connect(actionAbout, SIGNAL(activated()), MainClientWindow, SLOT(btnAboutPressed()));
        QObject::connect(actionQuit, SIGNAL(activated()), MainClientWindow, SLOT(close()));
        QObject::connect(edtServerAddr, SIGNAL(editingFinished()), MainClientWindow, SLOT(addrChanged()));
        QObject::connect(edtPort, SIGNAL(editingFinished()), MainClientWindow, SLOT(addrChanged()));

        QMetaObject::connectSlotsByName(MainClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainClientWindow)
    {
        MainClientWindow->setWindowTitle(QApplication::translate("MainClientWindow", "Klient", 0, QApplication::UnicodeUTF8));
        actionNewQuote->setText(QApplication::translate("MainClientWindow", "Nowy cytat", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewQuote->setToolTip(QApplication::translate("MainClientWindow", "Pobiera nowy cytat z serwera", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNewQuote->setShortcut(QApplication::translate("MainClientWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainClientWindow", "Zako\305\204cz", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainClientWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainClientWindow", "O programie", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainClientWindow", "Pobieraj z:", 0, QApplication::UnicodeUTF8));
        edtServerAddr->setText(QApplication::translate("MainClientWindow", "localhost", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainClientWindow", ":", 0, QApplication::UnicodeUTF8));
        edtPort->setInputMask(QApplication::translate("MainClientWindow", "99999; ", 0, QApplication::UnicodeUTF8));
        edtPort->setText(QApplication::translate("MainClientWindow", "44444", 0, QApplication::UnicodeUTF8));
        quoteArea->setHtml(QApplication::translate("MainClientWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; font-style:italic;\">Cze\305\233\304\207</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnNew->setText(QApplication::translate("MainClientWindow", "Nowy cytat", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainClientWindow: public Ui_MainClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLIENTWINDOW_H
