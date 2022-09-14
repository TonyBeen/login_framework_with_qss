QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


SOURCES += \
    source/main.cpp \
    source/login.cpp

HEADERS += \
    include/login.h

FORMS += \
    ui/login.ui


INCLUDEPATH += ./include
INCLUDEPATH += $(COMMON_PATH)/include

LIBS += -L$(COMMON_PATH)/lib

RESOURCES += \
    res/image.qrc \
    res/qss.qrc
