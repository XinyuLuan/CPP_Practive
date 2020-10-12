TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


##LIBS += -L"/usr/local/lib"
#LIBS += -L"~/Qt/SFML-2.0/lib"

#CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
#CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#INCLUDEPATH += "~/Qt/SFML-2.0/include"
#DEPENDPATH += "~/Qt/SFML-2.0/include"

LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"


SOURCES += \
    Tetrimino.cpp \
    main.cpp \
    well.cpp \
    game.cpp

HEADERS += \
    Tetrimino.h \
    well.h \
    game.h
