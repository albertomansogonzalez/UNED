#include "menuapartadispo.h"
#include <iostream>

MenuApartaDispo::MenuApartaDispo(GesRAE& gesRAE): gesRAE(gesRAE) {}

void MenuApartaDispo::mostrar()
{
    int idEdificio; //entre 1 y 5
    int diaEntrada, mesEntrada, anioEntrada;
    int duracion;

    std::cout << std::endl << "Apartamentos Disponibles" << std::endl;
    do {
        std::cout << "  Identificador de Edificio? ";
        std::cin >> idEdificio;
    }while((idEdificio < 1) || (idEdificio > 5));
    std::cout << "\tFecha de Entrada: Dia? ";
    std::cin >> diaEntrada;
    std::cout << "\tFecha de Entrada: Mes? ";
    std::cin >> mesEntrada;
    std::cout << "\tFecha de Entrada: Anio? ";
    std::cin >> anioEntrada;
    std::cout << "\tDias de duracion de la estancia? ";
    std::cin >> duracion;

    Fecha entrada(diaEntrada, mesEntrada, anioEntrada);
    std::cout << std::endl << "El edificio "<< gesRAE.getInfoEdificio(idEdificio).nombre << " desde el " << entrada.toString() << " y " << duracion << " dias de estancia, tendria disponibles:" << std::endl << std::endl;

    std::cout << "\t" << gesRAE.numApartaDisponible(idEdificio,TipoApartamento::Basico, entrada, entrada.calcularFechaFinal(duracion)) << " apartamentos de tipo Basico\n";
    std::cout << "\t" << gesRAE.numApartaDisponible(idEdificio,TipoApartamento::Normal, entrada, entrada.calcularFechaFinal(duracion)) << " apartamentos de tipo Normal\n";
    std::cout << "\t" << gesRAE.numApartaDisponible(idEdificio,TipoApartamento::Lujo, entrada, entrada.calcularFechaFinal(duracion)) << " apartamentos de tipo Lujo\n";
}
