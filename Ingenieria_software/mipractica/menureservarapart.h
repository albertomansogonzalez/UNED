#ifndef MENURESERVARAPART_H
#define MENURESERVARAPART_H

#include "imenu.h"
#include "gesrae.h"

class MenuReservarApart: public IMenu
{
public:
    MenuReservarApart(GesRAE& gesRAE);
    void mostrar() override;
private:
    GesRAE& gesRAE;
};

#endif // MENURESERVARAPART_H
