TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    application.cpp \
    eventlistener.cpp

HEADERS += \
    application.h \
    eventlistener.h


LIBS += -lpthread
