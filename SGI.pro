#-------------------------------------------------
#
# Project created by QtCreator 2014-09-8
#
#-------------------------------------------------

QT       += core gui
QT       += widgets


TARGET = SGI
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
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
    transform.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
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
    transform.h \
    controller.h

FORMS    += mainwindow.ui \
    addobjects.ui
