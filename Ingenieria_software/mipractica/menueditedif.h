#ifndef MENUEDITEDIF_H
#define MENUEDITEDIF_H

#include "imenu.h"
#include "gesrae.h"

class MenuEditEdif: public IMenu
{
public:
    MenuEditEdif(GesRAE& gesRAE);
    void mostrar() override;
private:
    GesRAE& gesRAE;
};

#endif // MENUEDITEDIF_H
