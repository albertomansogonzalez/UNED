#ifndef RESUMENMENSUAL_H
#define RESUMENMENSUAL_H

#include <vector>
#include "reserva.h"

struct ResumenMensual
{
    bool diasReservados[31]; //TODO valorar std::array
    std::vector<Reserva> reservas;
    std::size_t nReservados;
    std::size_t nLibres;
};

#endif // RESUMENMENSUAL_H
