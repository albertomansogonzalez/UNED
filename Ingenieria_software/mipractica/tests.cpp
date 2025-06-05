
#include "gesrae.h"

//#define DOCTEST_CONFIG_DISABLE    // para no usar doctest
#define DOCTEST_CONFIG_IMPLEMENT
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //para usar doctest tener un main
#include "doctest.h"


TEST_CASE("Pruebas de Fecha") {
    Fecha f1(4,6,2025);
    Fecha f2(4,6,2025);
    Fecha f3(4,8,2025);
    Fecha f4(5,6,2025);
    Fecha f5(4,6,2024);
    Fecha f6(3,6,2026);
    Fecha f7(3,6,2025);
    CHECK_FALSE(f1 < f2);
    //CHECK(f1 <= f2); //TODO falta sobrecargar el operador <=
    CHECK(f1 == f2);
    CHECK(f1 < f3);
    CHECK_FALSE(f3 == f1);
    CHECK_FALSE(f2 == f3);
    CHECK_FALSE(f3 < f4);
    CHECK(f3 > f4);
    CHECK(f5 < f6);
    CHECK_FALSE(f6 < f7);
}


TEST_CASE("Pruebas de GesRAE"){
    GesRAE gesRAE;
    gesRAE.aniadirEdificio(Edificio(1, "Neptuno", 1, 1, 1));
    gesRAE.aniadirEdificio(Edificio(2, "Saturno", 5, 6, 7));
    gesRAE.aniadirEdificio(Edificio(3, "Neptuno", 2, 8, 9));

    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(5,4,2025), Fecha(9,4,2025));
    //Junio 2025
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(26,5,2025), Fecha(1,6,2025));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(3,6,2025), Fecha(13,6,2025));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(22,6,2025), Fecha(24,6,2025));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(28,6,2025), Fecha(29,6,2025));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(30,6,2025), Fecha(4,7,2025));
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(2,7,2025), Fecha(22,7,2025));

    //Testear solape
    CHECK(gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(26,5,2024), Fecha(1,6,2024)));
    //CHECK_FALSE(gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(26,5,2023), Fecha(1,6,2023)));

}



