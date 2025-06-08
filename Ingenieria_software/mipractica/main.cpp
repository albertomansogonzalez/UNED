#include <iostream>
#include <menugesrae.h>
#include "gesrae.h"
#include "TiposComunes.h"

#include "doctest.h"

//TODO, ordenar ficheros en carpetas, src/, include/, test/ ...
int main()
{

    //Corre los tests:
    doctest::Context context;
    int res = context.run();
    if (context.shouldExit()) return res; //si el test fue solo para correr tests y salir



    GesRAE gesRAE;

    gesRAE.aniadirEdificio(Edificio(1, "Neptuno", 3, 12, 2));
    gesRAE.aniadirEdificio(Edificio(3, "Apolo", 8, 5, 3));
    gesRAE.aniadirEdificio(Edificio(4, "Zeus", 9, 6, 5));
    gesRAE.aniadirEdificio(Edificio(5, "Atenea", 4, 9, 2));

    MenuGesRAE menuGesRAE(gesRAE);
    menuGesRAE.mostrar();

    return 0;
}





