#ifndef MENULISTAREDIF_H
#define MENULISTAREDIF_H

#include "imenu.h"
#include "gesrae.h"

class MenuListarEdif: public IMenu
{
public:
    MenuListarEdif(GesRAE& gesRAE);
    void mostrar() override;
private:
    GesRAE& gesRAE;
};

#endif // MENULISTAREDIF_H
