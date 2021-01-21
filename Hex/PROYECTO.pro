#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T21:04:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROYECTO
TEMPLATE = app


SOURCES += main.cpp\
    Jugador.cpp \
    Tablero.cpp \
    Hex.cpp \
    T5.cpp \
    T10.cpp \
    T15.cpp

HEADERS  += \
    Jugador.h \
    Tablero.h \
    Hex.h \
    T5.h \
    T10.h \
    T15.h

FORMS    += \
    Hex.ui \
    T5.ui \
    T10.ui \
    T15.ui

DISTFILES +=
