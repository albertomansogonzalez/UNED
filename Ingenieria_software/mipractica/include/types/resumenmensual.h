#ifndef RESUMENMENSUAL_H
#define RESUMENMENSUAL_H

#include <vector>
#include "reserva.h"

struct ResumenMensual
{
    bool diasReservados[31]; //TODO valorar std::array
    std::vector<Reserva> reservas;
    int nReservados;
    int nLibres;
};

#endif // RESUMENMENSUAL_H
