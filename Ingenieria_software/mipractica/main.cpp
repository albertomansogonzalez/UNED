#include <iostream>
#include <menugesrae.h>
#include "gesrae.h"

#include "TiposComunes.h"


void test(GesRAE& gesRAE){

    gesRAE.aniadirEdificio(Edificio(1, "Neptuno", 2, 3, 4));
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

    std::cout << "MOSTRANDO RESERVAS DEL 06/2025" << std::endl;
    auto reservas = gesRAE.obtenerReservasMes(ReferenciaApartamento(TipoApartamento::Normal, 1, 1), 6, 2025);
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
