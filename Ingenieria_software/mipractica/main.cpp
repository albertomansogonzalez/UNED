#include <iostream>
#include <menugesrae.h>
#include "gesrae.h"

int main()
{

    GesRAE gesRAE;

    MenuGesRAE menuGesRAE(gesRAE);
    menuGesRAE.mostrar();

    return 0;
}
