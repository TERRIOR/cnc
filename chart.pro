#-------------------------------------------------
#
# Project created by QtCreator 2017-06-23T15:37:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = chart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    paowuxian.cpp \
    line.cpp \
    tuoyuan.cpp \
    point.cpp \
    paowindows.cpp \
    tuowindows.cpp \
    curve.cpp

HEADERS  += mainwindow.h \
       qcustomplot.h \
    paowuxian.h \
    line.h \
    tuoyuan.h \
    point.h \
    paowindows.h \
    tuowindows.h \
    curve.h

FORMS    += mainwindow.ui \
    paowindows.ui \
    tuowindows.ui
