TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        apartamento.cpp \
        edificio.cpp \
        fecha.cpp \
        gesrae.cpp \
        main.cpp \
        menuapartadispo.cpp \
        menueditedif.cpp \
        menugesrae.cpp \
        menulistaredif.cpp \
        menureservarapart.cpp \
        menureservasmensuales.cpp \
        referenciaapartamento.cpp \
        reserva.cpp \
        tests.cpp

HEADERS += \
    TiposComunes.h \
    apartamento.h \
    edificio.h \
    fecha.h \
    gesrae.h \
    imenu.h \
    menuapartadispo.h \
    menueditedif.h \
    menugesrae.h \
    menulistaredif.h \
    menureservarapart.h \
    menureservasmensuales.h \
    referenciaapartamento.h \
    reserva.h

INCLUDEPATH += .
