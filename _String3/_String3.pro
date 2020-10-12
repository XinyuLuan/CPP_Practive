TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    string.cpp \
    logentry.cpp \
    logview.cpp

HEADERS += \
    string.hpp \
    logentry.hpp
