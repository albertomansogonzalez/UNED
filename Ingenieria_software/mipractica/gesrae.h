#ifndef GESRAE_H
#define GESRAE_H

#include <map>
#include "edificio.h"
#include "TiposComunes.h"
#include "fecha.h"
#include "apartamento.h"

class GesRAE
{
public:
    GesRAE();

    void aniadirEdificio(Edificio edificio);
    const Edificio& getEdicicio(int id) const;
    int apartaDisponible(int idEdificio, TipoApartamento tipo, Fecha entrada, Fecha salida);
    Reserva crearReserva(int idEdificio, TipoApartamento tipo, int idApartaDispo, Fecha fechaEntrada, Fecha fechaSalida);
    void reservar(Reserva reserva);
    int numReservaAnio(int anio);

private:
    /**
     * @brief GesRAE puede almacenar hasta 5 edificios.
     *
     * Los edificios se ordenan según su id del 1 al 5, en posiciones [0] a [4] (@c idEdificio).
     */
    Edificio edificios[5];

    std::map<int,int> reservasPorAnio;

};

#endif // GESRAE_H






