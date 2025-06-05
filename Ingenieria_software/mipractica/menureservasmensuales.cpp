#include "menureservasmensuales.h"
#include <iostream>
#include "referenciaapartamento.h"
#include "reserva.h"

MenuReservasMensuales::MenuReservasMensuales(GesRAE &gesRAE): gesRAE(gesRAE) {}

void MenuReservasMensuales::mostrar()
{
    std::string refTexto; //TODO
    int mes;
    int anio;
    int idEdificio,idApartamento;
    std::cout << "Reservas Mensuales Apartamento" << std::endl;
    //std::cout << "Referencia Apartamento?"; //TODO
    //std::cin >> refTexto; //TODO
    std::cout << "id edificio? "; std::cin >> idEdificio;
    std::cout << "id apartamento? "; std::cin >> idApartamento;
    std::cout << "Seleccion mes? ";
    std::cin >> mes;
    std::cout << "Seleccion anio? ";
    std::cin >> anio;

    ReferenciaApartamento referencia (TipoApartamento::Normal, idApartamento, idEdificio); //TODO, es solo para probar

    std::cout << "\t\tEstado mensual Apartamento:" << referencia.getTexto() << std::endl;
    std::cout << "\t\t\t\tEdificio: " << gesRAE.getInfoEdificio(idEdificio).nombre << "\n"; //TODO


    std::cout << std::endl << std::endl;

    auto reservas = gesRAE.obtenerReservasMes(referencia, mes, anio);
    if (reservas.empty()) {
        std::cout << "\nNo hay reservas.\n";
    } else {
        //Mostrar todas las reservas:
        for (const Reserva& reserva: reservas){
            std::cout << "Reserva " << reserva.getNumReserva() << "/" << reserva.getFechaEntrada().getAnio() << ": Fecha entrada: " << reserva.getFechaEntrada().toString() <<  " y de " << reserva.getDuracion() << " dias\n";
        }
    }









}
