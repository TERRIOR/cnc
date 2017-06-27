#-------------------------------------------------
#
# Project created by QtCreator 2017-06-23T15:37:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = cnc
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
    curve.cpp \
    approxima.cpp \
    aboutme.cpp

HEADERS  += mainwindow.h \
       qcustomplot.h \
    paowuxian.h \
    line.h \
    tuoyuan.h \
    point.h \
    paowindows.h \
    tuowindows.h \
    curve.h \
    approxima.h \
    aboutme.h

FORMS    += mainwindow.ui \
    paowindows.ui \
    tuowindows.ui \
    aboutme.ui
