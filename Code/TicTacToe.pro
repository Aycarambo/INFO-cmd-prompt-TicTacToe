TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ai.cpp \
        board.cpp \
        functions.cpp \
        game.cpp \
        human.cpp \
        main.cpp \
        move.cpp

HEADERS += \
    TypeDef.h \
    ai.h \
    board.h \
    functions.h \
    game.h \
    human.h \
    move.h
QMAKE_LFLAGS+=-static
QMAKE_LFLAGS+=-static-libgcc
QMAKE_LFLAGS+=-static-libstdc++
