TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Commodity.cpp \
    NormalCommodity.cpp \
    OverseaCommodity.cpp \
    CommodityManage.cpp \
    function.cpp \
    SecondHandCommodity.cpp \
    BargainCommodity.cpp

HEADERS += \
    Commodity.h \
    OverseaCommodity.h \
    NormalCommodity.h \
    CommodityManage.h \
    function.h \
    SecondHandCommodity.h \
    BargainCommodity.h \
    header.h

DISTFILES +=
