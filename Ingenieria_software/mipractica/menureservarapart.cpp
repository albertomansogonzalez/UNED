#include "menureservarapart.h"
#include <iostream>

#include "reserva.h"

MenuReservarApart::MenuReservarApart(GesRAE &gesRAE): gesRAE(gesRAE) {}

void MenuReservarApart::mostrar()
{
    int idEdificio; //entre 1 y 5
    char letraTipo;
    TipoApartamento tipo;
    int diaEntrada, mesEntrada, anioEntrada;
    int duracion;
    char confirmar;

    std::cout << std::endl << "Reservar Apartamento:" << std::endl << std::endl;
    std::cout << "\tIdentificador de Edificio? ";
    std::cin >> idEdificio;
    std::cout << "\tTipo de Apartamento (B-Basico/N-Normal/L-Lujo)? ";
    std::cin >> letraTipo;
    switch (letraTipo) {
        case 'B': case 'b': tipo = TipoApartamento::Basico; break;
        case 'N': case 'n': tipo = TipoApartamento::Normal; break;
        case 'L': case 'l': tipo = TipoApartamento::Lujo; break;
    }
    std::cout << "\tFecha de Entrada: Dia? ";
    std::cin >> diaEntrada;
    std::cout << "\tFecha de Entrada: Mes? ";
    std::cin >> mesEntrada;
    std::cout << "\tFecha de Entrada: Anio? ";
    std::cin >> anioEntrada;
    std::cout << "\tDias de duracion de la estancia? ";
    std::cin >> duracion;

    Fecha entrada(diaEntrada, mesEntrada, anioEntrada);
    Fecha salida = Fecha::calcularFechaFinal(entrada, duracion);

    //std::cout << "Fecha de salida: " << salida.getFecha() << std::endl;

    //¿Hay Disponibilidad?
    int idApartaDispo = gesRAE.apartaDisponible(idEdificio, tipo, entrada, salida);
    if (idApartaDispo > 0){

        Reserva reserva = gesRAE.crearReserva(idEdificio, tipo, idApartaDispo, entrada, salida);
        std::cout << std::endl << "\t\tDatos de la Reserva: " << std::endl << std::endl;
        std::cout << "\tNumero de Reserva: " << reserva.getNumReserva() << "/" << reserva.getFechaEntrada().getAnio() << std::endl;
        std::cout << "\tEdificio: " << reserva.getNombreEdificio() << "(ID = " << reserva.getIdEdificio() << ")" << std::endl;
        std::cout << "\tReferencia Apartamento: " << reserva.getRefApartamento() << std::endl;
        std::cout << "\tFecha entrada: " << reserva.getFechaEntrada().getFecha() << std::endl;
        std::cout << "\tDuracion estancia: " << duracion << " dias" << std::endl;
        std::cout << "\tFecha salida: " << reserva.getFechaSalida().getFecha() << std::endl;

        std::cout << "Es correcto la operacion (S/N)? ";
        std::cin >> confirmar;
        if (confirmar == 'S' || confirmar == 's'){
            gesRAE.reservar(reserva);
        }else if (confirmar == 'N'){
            //No realizar la reserva
        }

    }else{
        std::cout << "No hay disponibilidad en esas fechas" << std::endl;
    }



}
