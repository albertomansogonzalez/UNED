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

    /**
     * @brief apartaDisponible
     * @param idEdificio
     * @param tipo
     * @param entrada
     * @param salida
     * @return Nº de apartamentos disponibles con estas caracteristicas
     */
    int numApartaDisponible(int idEdificio, TipoApartamento tipo, Fecha entrada, Fecha salida);

    /**
     * @brief reservar Devuelve los datos de la reserva, y ademas si \p confirmacion es true, la guarda en el sistema
     * @param confirmacion
     * @param idEdificio
     * @param tipo
     * @param fechaEntrada
     * @param fechaSalida
     * @return
     */
    Reserva reservar(bool confirmacion, int idEdificio, TipoApartamento tipo, Fecha fechaEntrada, Fecha fechaSalida);

    /**
     * @brief numReservaAnio Devulve nº reservas en un anio
     * @param anio
     * @return Nº reservas
     */
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






