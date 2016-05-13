QT += core
QT += network
QT -= gui

TARGET = App
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp \
    memory.cpp \
    cpu.cpp

HEADERS += \
    myserver.h \
    memory.h \
    cpu.h

