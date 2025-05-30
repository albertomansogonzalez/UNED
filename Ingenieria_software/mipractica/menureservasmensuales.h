#ifndef MENURESERVASMENSUALES_H
#define MENURESERVASMENSUALES_H

#include "imenu.h"
#include "gesrae.h"

class MenuReservasMensuales: public IMenu
{
public:
    MenuReservasMensuales(GesRAE& gesRAE);
    void mostrar() override;
private:
    GesRAE& gesRAE;
};

#endif // MENURESERVASMENSUALES_H
