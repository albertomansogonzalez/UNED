
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

TEST_CASE("Creacion de edificios"){
    GesRAE gesRAE;
    gesRAE.aniadirEdificio(Edificio(1, "Neptuno", 1, 1, 1));
    gesRAE.aniadirEdificio(Edificio(2, "Saturno", 5, 6, 7));
    gesRAE.aniadirEdificio(Edificio(3, "Jupiter", 2, 8, 9));
    gesRAE.aniadirEdificio(Edificio(4, "Urano", 5, 0, 3));
    gesRAE.aniadirEdificio(Edificio(5, "Pluton", 0, 3, 4));

    CHECK(gesRAE.getInfoEdificio(1).idEdificio == 1);
    CHECK(strcmp(gesRAE.getInfoEdificio(1).nombre, "Neptuno") == 0);
    CHECK(gesRAE.getInfoEdificio(1).nBasicos == 1);
    CHECK(gesRAE.getInfoEdificio(1).nNormales == 1);
    CHECK(gesRAE.getInfoEdificio(1).nLujo == 1);

    CHECK(gesRAE.getInfoEdificio(2).idEdificio == 2);
    CHECK(strcmp(gesRAE.getInfoEdificio(2).nombre, "Saturno") == 0);
    CHECK(gesRAE.getInfoEdificio(2).nBasicos == 5);
    CHECK(gesRAE.getInfoEdificio(2).nNormales == 6);
    CHECK(gesRAE.getInfoEdificio(2).nLujo == 7);

    CHECK(gesRAE.getInfoEdificio(3).idEdificio == 3);
    CHECK(strcmp(gesRAE.getInfoEdificio(3).nombre, "Jupiter") == 0);
    CHECK(gesRAE.getInfoEdificio(3).nBasicos == 2);
    CHECK(gesRAE.getInfoEdificio(3).nNormales == 8);
    CHECK(gesRAE.getInfoEdificio(3).nLujo == 9);

    CHECK(gesRAE.getInfoEdificio(4).idEdificio == 4);
    CHECK(strcmp(gesRAE.getInfoEdificio(4).nombre, "Urano") == 0);
    CHECK(gesRAE.getInfoEdificio(4).nBasicos == 5);
    CHECK(gesRAE.getInfoEdificio(4).nNormales == 0);
    CHECK(gesRAE.getInfoEdificio(4).nLujo == 3);

    CHECK(gesRAE.getInfoEdificio(5).idEdificio == 5);
    CHECK(strcmp(gesRAE.getInfoEdificio(5).nombre, "Pluton") == 0);
    CHECK(gesRAE.getInfoEdificio(5).nBasicos == 0);
    CHECK(gesRAE.getInfoEdificio(5).nNormales == 3);
    CHECK(gesRAE.getInfoEdificio(5).nLujo == 4);

    //Testear sobreescribir
    gesRAE.aniadirEdificio(Edificio(3, "Marte", 3, 6, 0));

    CHECK(gesRAE.getInfoEdificio(1).idEdificio == 1);
    CHECK(strcmp(gesRAE.getInfoEdificio(1).nombre, "Neptuno") == 0);
    CHECK(gesRAE.getInfoEdificio(1).nBasicos == 1);
    CHECK(gesRAE.getInfoEdificio(1).nNormales == 1);
    CHECK(gesRAE.getInfoEdificio(1).nLujo == 1);

    CHECK(gesRAE.getInfoEdificio(2).idEdificio == 2);
    CHECK(strcmp(gesRAE.getInfoEdificio(2).nombre, "Saturno") == 0);
    CHECK(gesRAE.getInfoEdificio(2).nBasicos == 5);
    CHECK(gesRAE.getInfoEdificio(2).nNormales == 6);
    CHECK(gesRAE.getInfoEdificio(2).nLujo == 7);

    CHECK(gesRAE.getInfoEdificio(3).idEdificio == 3);
    CHECK(strcmp(gesRAE.getInfoEdificio(3).nombre, "Marte") == 0);
    CHECK(gesRAE.getInfoEdificio(3).nBasicos == 3);
    CHECK(gesRAE.getInfoEdificio(3).nNormales == 6);
    CHECK(gesRAE.getInfoEdificio(3).nLujo == 0);

    CHECK(gesRAE.getInfoEdificio(4).idEdificio == 4);
    CHECK(strcmp(gesRAE.getInfoEdificio(4).nombre, "Urano") == 0);
    CHECK(gesRAE.getInfoEdificio(4).nBasicos == 5);
    CHECK(gesRAE.getInfoEdificio(4).nNormales == 0);
    CHECK(gesRAE.getInfoEdificio(4).nLujo == 3);

    CHECK(gesRAE.getInfoEdificio(5).idEdificio == 5);
    CHECK(strcmp(gesRAE.getInfoEdificio(5).nombre, "Pluton") == 0);
    CHECK(gesRAE.getInfoEdificio(5).nBasicos == 0);
    CHECK(gesRAE.getInfoEdificio(5).nNormales == 3);
    CHECK(gesRAE.getInfoEdificio(5).nLujo == 4);

}

TEST_CASE("Probar reservas y numero anuales"){
    GesRAE gesRAE;
    gesRAE.aniadirEdificio(Edificio(1, "Neptuno", 20, 20, 20));
    gesRAE.aniadirEdificio(Edificio(2, "Saturno", 20, 20, 20));
    gesRAE.aniadirEdificio(Edificio(3, "Urano", 20, 20, 20));
    CHECK(gesRAE.numReservaAnio(2024) == 0);
    CHECK(gesRAE.numReservaAnio(2025) == 0);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(5,4,2025), Fecha(9,4,2025));
    CHECK(gesRAE.numReservaAnio(2024) == 0);
    CHECK(gesRAE.numReservaAnio(2025) == 1);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(true, 1, TipoApartamento::Basico, Fecha(5,4,2024), Fecha(9,4,2024));
    CHECK(gesRAE.numReservaAnio(2024) == 1);
    CHECK(gesRAE.numReservaAnio(2025) == 1);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(true, 1, TipoApartamento::Lujo, Fecha(2,1,2025), Fecha(6,1,2025));
    CHECK(gesRAE.numReservaAnio(2024) == 1);
    CHECK(gesRAE.numReservaAnio(2025) == 2);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(6,1,2025), Fecha(17,1,2025));
    CHECK(gesRAE.numReservaAnio(2024) == 1);
    CHECK(gesRAE.numReservaAnio(2025) == 3);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(true, 2, TipoApartamento::Lujo, Fecha(6,1,2025), Fecha(17,1,2025));
    CHECK(gesRAE.numReservaAnio(2024) == 1);
    CHECK(gesRAE.numReservaAnio(2025) == 4);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(true, 2, TipoApartamento::Lujo, Fecha(8,3,2025), Fecha(17,5,2025));
    CHECK(gesRAE.numReservaAnio(2024) == 1);
    CHECK(gesRAE.numReservaAnio(2025) == 5);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(false, 2, TipoApartamento::Lujo, Fecha(8,3,2025), Fecha(17,5,2025));
    CHECK(gesRAE.numReservaAnio(2024) == 1);
    CHECK(gesRAE.numReservaAnio(2025) == 5);
    CHECK(gesRAE.numReservaAnio(2026) == 0);
    gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(5,7,2024), Fecha(7,7,2024));
    CHECK(gesRAE.numReservaAnio(2024) == 2);
    gesRAE.reservar(true, 3, TipoApartamento::Basico, Fecha(5,7,2024), Fecha(7,7,2024));
    CHECK(gesRAE.numReservaAnio(2024) == 3);
    gesRAE.reservar(true, 3, TipoApartamento::Basico, Fecha(5,7,2024), Fecha(7,7,2024));
    CHECK(gesRAE.numReservaAnio(2024) == 4);
    CHECK(gesRAE.numReservaAnio(2025) == 5);
    CHECK(gesRAE.numReservaAnio(2026) == 0);


    //Junio 2026
        gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(26,5,2026), Fecha(1,6,2026));
        gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(3,6,2026), Fecha(13,6,2026));
        gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(22,6,2026), Fecha(24,6,2026));
        gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(28,6,2026), Fecha(29,6,2026));
        gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(30,6,2026), Fecha(4,7,2026));
        gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(2,7,2026), Fecha(22,7,2026));

    CHECK(gesRAE.numReservaAnio(2026) == 6);

}

TEST_CASE("Numero aparta disponible"){
    GesRAE gesRAE;
    gesRAE.aniadirEdificio(Edificio(1, "Neptuno", 0, 1, 1));
    gesRAE.aniadirEdificio(Edificio(2, "Saturno", 5, 6, 7));

    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(4,5,2025), Fecha(5,6,2025)) == 0);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(4,5,2025), Fecha(5,6,2030)) == 0);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(1,5,2023), Fecha(6,7,2024)) == 0);


    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Normal, Fecha(4,5,2025), Fecha(5,6,2025)) == 1);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Normal, Fecha(4,5,2025), Fecha(5,6,2030)) == 1);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Normal, Fecha(1,5,2023), Fecha(6,7,2024)) == 1);

    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Lujo, Fecha(4,5,2025), Fecha(5,6,2025)) == 1);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Lujo, Fecha(4,5,2025), Fecha(5,6,2030)) == 1);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Lujo, Fecha(1,5,2023), Fecha(6,7,2024)) == 1);


    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Basico, Fecha(4,5,2025), Fecha(5,6,2025)) == 5);
    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Basico, Fecha(4,5,2025), Fecha(5,6,2030)) == 5);
    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Basico, Fecha(1,5,2023), Fecha(6,7,2024)) == 5);


    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Normal, Fecha(4,5,2025), Fecha(5,6,2025)) == 6);
    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Normal, Fecha(4,5,2025), Fecha(5,6,2030)) == 6);
    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Normal, Fecha(1,5,2023), Fecha(6,7,2024)) == 6);

    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Lujo, Fecha(4,5,2025), Fecha(5,6,2025)) == 7);
    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Lujo, Fecha(4,5,2025), Fecha(5,6,2030)) == 7);
    CHECK(gesRAE.numApartaDisponible(2, TipoApartamento::Lujo, Fecha(1,5,2023), Fecha(6,7,2024)) == 7);
}

TEST_CASE("Disminuir disponibidad al reservar"){
    GesRAE gesRAE;
    gesRAE.aniadirEdificio(Edificio(5, "Saturno", 5, 0, 0));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 5);
    //TODO, al reservar
    gesRAE.reservar(false, 5,TipoApartamento::Basico, Fecha(3,5,2025), Fecha(6,5,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 5);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,5,2025), Fecha(6,5,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 4);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,6,2025), Fecha(6,6,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 4);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,7,2025), Fecha(6,7,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 4);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,7,2025), Fecha(6,7,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 3);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,7,2025), Fecha(6,7,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 2);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,7,2025), Fecha(6,7,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 1);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,7,2025), Fecha(6,7,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 0);
    gesRAE.reservar(true, 5,TipoApartamento::Basico, Fecha(3,7,2025), Fecha(6,7,2025));
    CHECK(gesRAE.numApartaDisponible(5, TipoApartamento::Basico, Fecha(1,1,2025), Fecha(20,12,2025)) == 0);
}

TEST_CASE("Disponibilidad de apartamentos"){
//Testear solape
    GesRAE gesRAE;
    gesRAE.aniadirEdificio(Edificio(1, "Saturno", 5, 0, 0));
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Normal, Fecha(26,5,2027), Fecha(1,6,2027)) == 0);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Lujo, Fecha(26,5,2027), Fecha(1,6,2027)) == 0);

    gesRAE.reservar(true, 1, TipoApartamento::Basico, Fecha(26,5,2027), Fecha(1,6,2027));
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(3,4,2027), Fecha(10,5,2027)) == 5);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(2,6,2027), Fecha(3,8,2027)) == 5);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(20,4,2027), Fecha(25,5,2027)) == 5);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(20,5,2027), Fecha(27,5,2027)) == 4);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(20,5,2027), Fecha(26,5,2027)) == 4);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(1,6,2027), Fecha(5,6,2027)) == 4);
    CHECK(gesRAE.numApartaDisponible(1, TipoApartamento::Basico, Fecha(26,5,2027), Fecha(2,6,2027)) == 4);

    //reserva que no se puede hacer:
    CHECK(gesRAE.numReservaAnio(2027) == 1);
    CHECK_FALSE(gesRAE.reservar(true, 1, TipoApartamento::Normal, Fecha(26,5,2027), Fecha(1,6,2027)));
    CHECK(gesRAE.numReservaAnio(2027) == 1); //se mantiene el mismo nº de reservas


    gesRAE.aniadirEdificio(Edificio(2, "Tierra", 2, 0, 0));
    gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(26,5,2027), Fecha(1,6,2027));
    CHECK(gesRAE.numReservaAnio(2027) == 2);
    gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(28,5,2027), Fecha(29,5,2027));
    CHECK(gesRAE.numReservaAnio(2027) == 3);
    //reserva que no se puede:
    CHECK_FALSE(gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(27,5,2027), Fecha(30,5,2027)));
    CHECK(gesRAE.numReservaAnio(2027) == 3); //se mantiene
    //reserva que no se puede:
    CHECK_FALSE(gesRAE.reservar(true, 2, TipoApartamento::Normal, Fecha(27,4,2027), Fecha(30,4,2027)));
    CHECK(gesRAE.numReservaAnio(2027) == 3); //se mantiene
    //reserva que no se puede:
    CHECK_FALSE(gesRAE.reservar(true, 2, TipoApartamento::Lujo, Fecha(27,4,2027), Fecha(30,4,2027)));
    CHECK(gesRAE.numReservaAnio(2027) == 3); //se mantiene
}
