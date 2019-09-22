TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Arma.cpp \
        enemigo.cpp \
        item.cpp \
        login.cpp \
        main.cpp \
        mapa.cpp \
        menu.cpp \
        obstaculo.cpp \
        personaje.cpp

DISTFILES += \
    Armas.txt \
    Items.txt

HEADERS += \
    Arma.h \
    enemigo.h \
    item.h \
    login.h \
    mapa.h \
    menu.h \
    obstaculo.h \
    personaje.h
