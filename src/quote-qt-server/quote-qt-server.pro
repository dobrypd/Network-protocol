#-------------------------------------------------
#
# Project created by QtCreator 2011-05-24T03:25:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

TARGET = quote-qt-server
TEMPLATE = app


SOURCES += main.cpp\
        mainserverwindow.cpp \
    db.cpp \
    server.cpp \
    utils.cpp

HEADERS  += mainserverwindow.h \
    db.h \
    utils.h \
    server.h \
    protocolconsts.h

FORMS    += mainserverwindow.ui
