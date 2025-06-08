TEMPLATE =
app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        resumenmensual.cpp \
        src/types/fecha.cpp \
        src/core/apartamento.cpp \
        src/core/edificio.cpp \
        src/core/gesrae.cpp \
        src/core/referenciaapartamento.cpp \
        src/core/reserva.cpp \
        src/ui/menuapartadispo.cpp \
        src/ui/menueditedif.cpp \
        src/ui/menugesrae.cpp \
        src/ui/menulistaredif.cpp \
        src/ui/menureservarapart.cpp \
        src/ui/menureservasmensuales.cpp \
        test/tests.cpp

HEADERS += \
    include/types/TiposComunes.h \
    include/types/fecha.h \
    include/core/apartamento.h \
    include/core/edificio.h \
    include/core/gesrae.h \
    include/core/reserva.h \
    include/core/referenciaapartamento.h \
    include/ui/imenu.h \
    include/ui/menuapartadispo.h \
    include/ui/menueditedif.h \
    include/ui/menugesrae.h \
    include/ui/menulistaredif.h \
    include/ui/menureservarapart.h \
    include/ui/menureservasmensuales.h \
    resumenmensual.h

INCLUDEPATH += external \
    include/types \
    include/core \
    include/ui
