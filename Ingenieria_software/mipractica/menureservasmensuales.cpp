#include "menureservasmensuales.h"
#include <iostream>

MenuReservasMensuales::MenuReservasMensuales(GesRAE &gesRAE): gesRAE(gesRAE) {}

void MenuReservasMensuales::mostrar()
{
    std::cout << "Reservas Mensuales Apartamento" << std::endl;
}
