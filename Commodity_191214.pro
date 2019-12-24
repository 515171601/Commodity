TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Commodity.cpp \
    CommodityManage.cpp \
    function.cpp

HEADERS += \
    CommodityManage.h \
    Commodity.h \
    function.h
