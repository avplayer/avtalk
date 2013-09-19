#-------------------------------------------------
#
# Project created by QtCreator 2013-09-19T07:11:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = avtalk
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
LIBS += -lboost_system -lboost_thread -lrtmp -lpulse-simple -lpulse

SOURCES += main.cpp\
        mainwindow.cpp \
    media_connection.cpp \
    audio_capture.cpp

HEADERS  += mainwindow.h \
    media_connection.h \
    common.h \
    audio_capture.h

FORMS    += mainwindow.ui
