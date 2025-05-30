#include "menugesrae.h"
#include <iostream>
#include <memory>
#include "imenu.h"
#include "menueditedif.h"
#include "menulistaredif.h"
#include "menuapartadispo.h"
#include "menureservarapart.h"
#include "menureservasmensuales.h"

MenuGesRAE::MenuGesRAE(GesRAE& gesRAE): gesRAE(gesRAE) {
    titulo = "GesRAE: Gestion de Reservas Apartamentos-Edificios";
}

void MenuGesRAE::mostrar()
{
    char opcion;
    std::unique_ptr<IMenu> submenu;

    while(1){
        std::cout << std::endl << titulo << std::endl;
        std::cout << std::endl;
        std::cout << "  Editar Edificio                   (Pulsar E)" << std::endl;
        std::cout << "  Listar Edificios                  (Pulsar L)" << std::endl;
        std::cout << "  Apartamentos Disponibles          (Pulsar A)" << std::endl;
        std::cout << "  Reservar Apartamento              (Pulsar R)" << std::endl;
        std::cout << "  Reservas Mensuales Apartamento    (Pulsar M)" << std::endl;
        std::cout << "  Salir                             (Pulsar S)" << std::endl;
        std::cout << std::endl;
        std::cout << "Teclear una opcion valida (E|L|A|R|M|S)?";

        std::cin >> opcion;


        switch (opcion){
            case 'E': case 'e': submenu = std::make_unique<MenuEditEdif>(gesRAE); break;
            case 'L': case 'l': submenu = std::make_unique<MenuListarEdif>(gesRAE); break;
            case 'A': case 'a': submenu = std::make_unique<MenuApartaDispo>(gesRAE); break;
            case 'R': case 'r': submenu = std::make_unique<MenuReservarApart>(gesRAE); break;
            case 'M': case 'm': submenu = std::make_unique<MenuReservasMensuales>(gesRAE); break;
            case 'S': case 's': std::cout << "Saliendo" << std::endl ; return; break;
        }

        submenu->mostrar();
    }

}
