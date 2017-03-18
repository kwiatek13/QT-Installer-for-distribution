#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T11:23:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = instalator
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    system_chck.cpp \
    partition.cpp \
    instalacja_1.cpp \
    instalacja_2_64.cpp \
    Instalacja2_32.cpp

HEADERS  += mainwindow.h \
    system_chck.h \
    partition.h \
    instalacja_1.h \
    instalacja_2_64.h \
    instalacja_2_32.h

FORMS    += mainwindow.ui
