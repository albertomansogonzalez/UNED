#ifndef MENUGESRAE_H
#define MENUGESRAE_H

#include <string>

#include "imenu.h"
#include "gesrae.h"

class MenuGesRAE: public IMenu
{
public:
    MenuGesRAE(GesRAE& gesRAE);
    void mostrar() override;
private:
    GesRAE& gesRAE;
    std::string titulo;
};

#endif // MENUGESRAE_H
