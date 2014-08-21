#-------------------------------------------------
#
# Project created by QtCreator 2014-08-19T21:45:19
#
#-------------------------------------------------

QT       += core gui
QT       += widgets


TARGET = SGI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mediator.cpp \
    window.cpp \
    viewport.cpp \
    point.cpp \
    line.cpp \
    geometricshape.cpp \
    geometricshapefactory.cpp \
    displayfile.cpp \
    polygon.cpp \
    addobjects.cpp \
    coordinate.cpp \
    test.cpp \
    transform.cpp

HEADERS  += mainwindow.h \
    mediator.h \
    window.h \
    viewport.h \
    point.h \
    line.h \
    geometricshape.h \
    geometricshapefactory.h \
    displayfile.h \
    polygon.h \
    addobjects.h \
    coordinate.h \
    test.h \
    transform.h

FORMS    += mainwindow.ui \
    addobjects.ui
