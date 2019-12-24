TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Commodity.cpp \
    NormalCommodity.cpp \
    OverseaCommodity.cpp

HEADERS += \
    Commodity.h \
    OverseaCommodity.h \
    NormalCommodity.h
