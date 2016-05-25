QT += core
QT -= gui

CONFIG += c++11

TARGET = lab1-exp1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../../timer.cpp \
    ../../bigint/BigInteger.cc \
    ../../bigint/BigIntegerAlgorithms.cc \
    ../../bigint/BigIntegerUtils.cc \
    ../../bigint/BigUnsigned.cc \
    ../../bigint/BigUnsignedInABase.cc

HEADERS += \
    ../../timer.h \
    ../../bigint/BigInteger.hh \
    ../../bigint/BigIntegerAlgorithms.hh \
    ../../bigint/BigIntegerLibrary.hh \
    ../../bigint/BigIntegerUtils.hh \
    ../../bigint/BigUnsigned.hh \
    ../../bigint/BigUnsignedInABase.hh \
    ../../bigint/NumberlikeArray.hh
