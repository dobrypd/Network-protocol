#-------------------------------------------------
#
# Project created by QtCreator 2011-05-24T01:51:45
#
#-------------------------------------------------

QT       += core gui
QT       += network

TARGET = quote-qt-client
TEMPLATE = app


SOURCES += main.cpp\
        mainclientwindow.cpp \
    client.cpp \
    rand64.cpp

HEADERS  += mainclientwindow.h \
    client.h \
    ../quote-qt-server/protocolconsts.h \
    rand64.h

FORMS    += mainclientwindow.ui
