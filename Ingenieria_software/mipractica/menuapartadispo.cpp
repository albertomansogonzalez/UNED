#include "menuapartadispo.h"
#include <iostream>

MenuApartaDispo::MenuApartaDispo(GesRAE& gesRAE): gesRAE(gesRAE) {}

void MenuApartaDispo::mostrar()
{
    std::cout << "Apartamentos Disponibles" << std::endl;
}
