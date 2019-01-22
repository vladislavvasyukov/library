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
    main_window\main_window.cpp \
    adding_book\add_book.cpp \
    adding_reader\add_reader.cpp \
    return_book\return_book.cpp \
    deleting_reader\delete_reader.cpp \
    issuing_books\issue_books.cpp \
    delete_book\delete_book.cpp

HEADERS += \
    main_window\main_window.h \
    adding_book\add_book.h \
    adding_reader\add_reader.h \
    return_book\return_book.h \
    deleting_reader\delete_reader.h \
    issuing_books\issue_books.h \
    delete_book\delete_book.h

FORMS += \
    main_window\main_window.ui \
    adding_book\add_book.ui \
    adding_reader\add_reader.ui \
    return_book\return_book.ui \
    deleting_reader\delete_reader.ui \
    issuing_books\issue_books.ui \
    delete_book\delete_book.ui
