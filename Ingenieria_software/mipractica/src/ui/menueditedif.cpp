#include "menueditedif.h"
#include <iostream>

#include "edificio.h"

MenuEditEdif::MenuEditEdif(GesRAE &gesRAE): gesRAE(gesRAE) {

}

void MenuEditEdif::mostrar()
{
    int idEdificio;
    char nombre [20];
    int nBasicos, nNormales, nLujo;
    char confirmar;

    std::cout << "  Editar Edificio" << std::endl;
    std::cout << std::endl;
    do {
        std::cout << "  Identificador (numero entre 1 y 5)? ";
        std::cin >> idEdificio;
    }while((idEdificio < 1) || (idEdificio > 5));
    std::cout << "  Nombre (entre 1 y 20 caracteres)? ";
    std::cin >> nombre;
    std::cout << "  Numero de Apartamentos Basicos? ";
    std::cin >> nBasicos;
    std::cout << "  Numero de Apartamentos Normales? ";
    std::cin >> nNormales;
    std::cout << "  Numero de Apartamentos Lujo? ";
    std::cin >> nLujo;

    std::cout << "IMPORTANTE: Esta opcion borra los datos anteriores." << std::endl;
    std::cout << "Son correctos los nuevos datos (S/N)=? ";
    std::cin >> confirmar;
    if (confirmar == 'S' || confirmar == 's'){
        gesRAE.aniadirEdificio(Edificio(idEdificio, nombre, nBasicos, nNormales, nLujo));
    }else if (confirmar == 'N'){
        //No se aniade el Edificio
    }
}












