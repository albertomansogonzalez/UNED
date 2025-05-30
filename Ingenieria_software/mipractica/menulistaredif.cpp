#include "menulistaredif.h"
#include <iostream>

MenuListarEdif::MenuListarEdif(GesRAE &gesRAE): gesRAE(gesRAE) {}

void MenuListarEdif::mostrar()
{
    std::cout << std::endl << "Id\tNombre\tAptos Basicos\tAptos Normales\tApt de Lujo" << std::endl;
    for (int i = 1; i <= 5; i++){
        const Edificio& e = gesRAE.getEdicicio(i);
        if (e.getIdEdificio() != -1){
            std::cout << e.getIdEdificio() << '\t'
                      << e.getNombre()     << '\t' << '\t'
                      << e.getNBasicos()   << '\t' << '\t'
                      << e.getNNormales()  << '\t' << '\t'
                      << e.getNLujo() << std::endl;
        }
    }
}
