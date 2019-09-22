TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Arma.cpp \
        enemigo.cpp \
        login.cpp \
        main.cpp \
        mapa.cpp \
        personaje.cpp

DISTFILES += \
    Armas.txt

HEADERS += \
    Arma.h \
    enemigo.h \
    login.h \
    mapa.h \
    personaje.h
