#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T22:34:33
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = lab0-5
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    timer.cpp \
    bigint/BigInteger.cc \
    bigint/BigIntegerAlgorithms.cc \
    bigint/BigIntegerUtils.cc \
    bigint/BigUnsigned.cc \
    bigint/BigUnsignedInABase.cc

HEADERS += \
    timer.h \
    bigint/BigInteger.hh \
    bigint/BigIntegerAlgorithms.hh \
    bigint/BigIntegerLibrary.hh \
    bigint/BigIntegerUtils.hh \
    bigint/BigUnsigned.hh \
    bigint/BigUnsignedInABase.hh \
    bigint/NumberlikeArray.hh
