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

    #ifdef DATOS_POR_DEFECTO
    gesRAE.aniadirEdificio(Edificio(1, "Neptuno", 3, 12, 2));
    gesRAE.aniadirEdificio(Edificio(3, "Apolo", 8, 5, 3));
    gesRAE.aniadirEdificio(Edificio(4, "Zeus", 9, 6, 5));
    gesRAE.aniadirEdificio(Edificio(5, "Atenea", 4, 9, 2));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(8,6,2025), Fecha(12,6,2025));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(2,6,2024), Fecha(3,6,2024));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(2,7,2025), Fecha(3,7,2025));
    gesRAE.reservar(true, 3, TipoApartamento::Normal, Fecha(8,6,2025), Fecha(12,6,2025));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(2,6,2025), Fecha(4,6,2025));
     #endif


    MenuGesRAE menuGesRAE(gesRAE);
    menuGesRAE.mostrar();

    return 0;
}





