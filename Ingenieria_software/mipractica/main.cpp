#include <iostream>
#include <menugesrae.h>
#include "gesrae.h"

#include "TiposComunes.h"


void test(GesRAE& gesRAE){



    Fecha f1(4,6,2025);
    Fecha f2(4,6,2025);
    Fecha f3(4,8,2025);
    Fecha f4(5,6,2025);
    Fecha f5(4,6,2024);
    Fecha f6(3,6,2026);
    Fecha f7(3,6,2025);

    std::cout << std::endl;

    std::cout << (f1 < f2) << std::endl;    //0
    std::cout << (f1 == f2) << std::endl;   //1
    std::cout << (f1 < f3 )<< std::endl;    //1
    std::cout << (f3 < f1 )<< std::endl;    //0
    std::cout << (f2 == f3) << std::endl;   //0
    std::cout << (f3 < f4 )<< std::endl;    //0
    std::cout << (f3 > f4 )<< std::endl;    //1
    std::cout << (f5 < f6 )<< std::endl;    //1
    std::cout << (f6 < f7 )<< std::endl;    //0


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
    std::cout << "\nSOLAPE\n";
    if (gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(26,5,2024), Fecha(1,6,2024))){
        std::cout << "reserva sin solape\n";
    }else{
        std::cout << "error, hay solape\n";
    }
    if (gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(26,5,2023), Fecha(1,6,2023))){
        std::cout << "reserva sin solape\n";
    }else{
        std::cout << "error, hay solape\n";
    }
    if (gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(26,5,2022), Fecha(1,6,2022))){
        std::cout << "reserva sin solape\n";
    }else{
        std::cout << "error, hay solape\n";
    }
    if (!gesRAE.reservar(true, 2, TipoApartamento::Basico, Fecha(24,5,2024), Fecha(3,6,2024))){
        std::cout << "reserva sin solape\n";
    }else{
        std::cout << "error, hay solape\n";
    }

    auto reservas = gesRAE.obtenerReservasMes(ReferenciaApartamento(TipoApartamento::Basico, 2, 1), 5, 2024);
    for (const Reserva& reserva: reservas){
        std::cout << "Reserva " << reserva.getNumReserva() << "/" << reserva.getFechaEntrada().getAnio() << ": Fecha entrada: " << reserva.getFechaEntrada().toString() <<  " y de " << reserva.getDuracion() << " dias\n";
    }

    //gesRAE.numApartaDisponible(idEdificio, tipo, entrada, salida)





    exit(0);

    std::cout << "MOSTRANDO RESERVAS DEL 06/2025" << std::endl;
    reservas = gesRAE.obtenerReservasMes(ReferenciaApartamento(TipoApartamento::Normal, 1, 1), 6, 2025);
    if (reservas.empty()) {
        std::cout << "\nNo hay reservas.\n";
    } else {
        //Mostrar todas las reservas:
        for (const Reserva& reserva: reservas){
            std::cout << "Reserva " << reserva.getNumReserva() << "/" << reserva.getFechaEntrada().getAnio() << ": Fecha entrada: " << reserva.getFechaEntrada().toString() <<  " y de " << reserva.getDuracion() << " dias\n";
        }
    }

    std::cout << "MOSTRANDO RESERVAS DEL 07/2025" << std::endl;
    reservas = gesRAE.obtenerReservasMes(ReferenciaApartamento(TipoApartamento::Normal, 1, 1), 7, 2025);
    if (reservas.empty()) {
        std::cout << "\nNo hay reservas.\n";
    } else {
        //Mostrar todas las reservas:
        for (const Reserva& reserva: reservas){
            std::cout << "Reserva " << reserva.getNumReserva() << "/" << reserva.getFechaEntrada().getAnio() << ": Fecha entrada: " << reserva.getFechaEntrada().toString() <<  " y de " << reserva.getDuracion() << " dias\n";
        }
    }
}

int main()
{

    GesRAE gesRAE;

    test(gesRAE);

    MenuGesRAE menuGesRAE(gesRAE);
    menuGesRAE.mostrar();

    return 0;
}
