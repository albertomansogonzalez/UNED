#ifndef MENUAPARTADISPO_H
#define MENUAPARTADISPO_H

#include "imenu.h"
#include "gesrae.h"

class MenuApartaDispo: public IMenu
{
public:
    MenuApartaDispo(GesRAE& gesRAE);
    void mostrar() override;
private:
    GesRAE& gesRAE;
};

#endif // MENUAPARTADISPO_H
