TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    application.cpp \
    eventlistener.cpp \
    event.cpp

HEADERS += \
    application.h \
    eventlistener.h \
    event.h


LIBS += -lpthread
