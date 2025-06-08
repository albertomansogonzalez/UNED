#include "menureservasmensuales.h"
#include <iostream>
#include <iomanip>
#include "referenciaapartamento.h"
#include "reserva.h"
#include "resumenmensual.h"

MenuReservasMensuales::MenuReservasMensuales(GesRAE &gesRAE): gesRAE(gesRAE) {}

void MenuReservasMensuales::mostrar()
{
    std::string refTexto; //TODO
    int mes;
    int anio;
    std::cout << "Reservas Mensuales Apartamento" << std::endl;
    std::cout << "Referencia Apartamento? ";
    std::cin >> refTexto;
    ReferenciaApartamento referencia(refTexto); //TODO que pasa si formato incorrecto??

    std::cout << "Seleccion mes? ";
    std::cin >> mes;
    std::cout << "Seleccion anio? ";
    std::cin >> anio;

    std::cout << "\t\tEstado mensual Apartamento:" << referencia.getTexto() << std::endl;
    std::cout << "\t\t\tEdificio: " << gesRAE.getInfoEdificio(referencia.getIdEdificio()).nombre << "\n"; //TODO

    //TODO Printear el calendarios
    int primerDia = Fecha::diaDeLaSemana(1, mes, anio);
    // Ajustamos para que 0 sea domingo, 1 lunes, ..., 6 sábado
    int inicio = (primerDia + 6) % 7;

    std::cout << Fecha::nombreMes(mes) << "\t\t\t" << anio << "\n";
        std::cout << "Do Lu Ma Mi Ju Vi Sa\n";

    // Imprimimos espacios para el primer día
    for (int i = 0; i < inicio; i++) {
        std::cout << "   ";
    }

    ResumenMensual resumen =  gesRAE.obtenerResumenMensual(referencia, mes, anio);

    //Pintar los dias del mes
    int totalDias = resumen.nLibres + resumen.nReservados;
    for (int dia = 1; dia <= totalDias; dia++) {
        if (resumen.diasReservados[dia]){
            std::cout << "Re ";
        }
    else{
        std::cout << std::setw(2) << dia << " ";
    }
    if ((dia + inicio) % 7 == 0)
            std::cout << "\n";
    }
    std::cout << "\n";




    if (resumen.reservas.empty()) {
        std::cout << "\nNo hay reservas.\n";
    } else {
        //Mostrar todas las reservas:
        for (const Reserva& reserva: resumen.reservas){
            //TODO solo mostrar las reservas de ese anio
            std::cout << "Reserva " << reserva.getNumReserva() << "/" << reserva.getFechaEntrada().getAnio() << ": Fecha entrada: " << reserva.getFechaEntrada().toString() <<  " y de " << reserva.getDuracion() << " dias\n";
        }
    }

    std::cout << "Total dias reservados del mes:" << resumen.nReservados << " dias\n";
    std::cout << "Total dias libres del mes:" << resumen.nLibres << " dias\n";






}
