#include "menulistaredif.h"
#include <iostream>

MenuListarEdif::MenuListarEdif(GesRAE &gesRAE): gesRAE(gesRAE) {}

void MenuListarEdif::mostrar()
{
    std::cout << std::endl << "Id\tNombre\tAptos Basicos\tAptos Normales\tApt de Lujo" << std::endl;
    for (int i = 1; i <= 5; i++){
        const InfoEdificio& e = gesRAE.getInfoEdificio(i);
        if (e.idEdificio != -1){
            std::cout << e.idEdificio << '\t'
                      << e.nombre     << '\t' << '\t'
                      << e.nBasicos   << '\t' << '\t'
                      << e.nNormales  << '\t' << '\t'
                      << e.nLujo << std::endl;
        }
    }
}
