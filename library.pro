#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T21:38:11
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = library
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow\mainwindow.cpp \
    addbook\addbook.cpp \
    addreader\addreader.cpp \
    returnbook\returnbook.cpp \
    deletereader\deletereader.cpp \
    issuedbooks\issuedbooks.cpp

HEADERS += \
    mainwindow\mainwindow.h \
    addbook\addbook.h \
    addreader\addreader.h \
    returnbook\returnbook.h \
    deletereader\deletereader.h \
    issuedbooks\issuedbooks.h

FORMS += \
    mainwindow\mainwindow.ui \
    addbook\addbook.ui \
    addreader\addreader.ui \
    returnbook\returnbook.ui \
    deletereader\deletereader.ui \
    issuedbooks\issuedbooks.ui
