#include <iostream>
#include <menugesrae.h>
#include "gesrae.h"
#include "TiposComunes.h"

#include "doctest.h"


int main()
{

    //Corre los tests:
    doctest::Context context;
    int res = context.run();
    if (context.shouldExit()) return res; //si el test fue solo para correr tests y salir



    GesRAE gesRAE;

    MenuGesRAE menuGesRAE(gesRAE);
    menuGesRAE.mostrar();

    return 0;
}





