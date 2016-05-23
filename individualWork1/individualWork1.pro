QT += core
QT -= gui

CONFIG += c++11

TARGET = individualWork1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    percolation.cpp \
    percolationstats.cpp \
    timer.cpp

HEADERS += \
    percolation.h \
    percolationstats.h \
    timer.h
