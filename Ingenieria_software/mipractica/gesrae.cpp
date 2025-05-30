#include "gesrae.h"

GesRAE::GesRAE() {}

void GesRAE::aniadirEdificio(Edificio edificio)
{
    this->edificios[edificio.getIdEdificio() - 1] = edificio;
}

/**
 * id entre 1 y 5
 */
const Edificio& GesRAE::getEdicicio(int id) const
{
    return this->edificios[id - 1];
}

/**
 * @brief GesRAE::apartaDisponible Devuelve el id del primer apartamento disponible.
 * @param idEdificio
 * @param tipo
 * @param entrada
 * @param salida
 * @return
 */
int GesRAE::apartaDisponible(int idEdificio, TipoApartamento tipo, Fecha entrada, Fecha salida)
{
    return edificios[idEdificio - 1].getApartamentoDisponible(tipo, entrada, salida);
}

/**
 * @brief GesRAE::crearReserva Devuelve una posible reserva, pero para confirmar: GesRAE::reservar()
 * @param idEdificio
 * @param nombreEdificio
 * @param tipo
 * @param idApartaDispo
 * @param fechaEntrada
 * @param fechaSalida
 * @return
 */
Reserva GesRAE::crearReserva(int idEdificio, TipoApartamento tipo,int idApartaDispo, Fecha fechaEntrada, Fecha fechaSalida)
{

    //numero de reserva = nº reservar total de ese año + 1
    return Reserva(reservasPorAnio[fechaEntrada.getAnio()] + 1, idEdificio, edificios[idEdificio - 1].getNombre(), tipo, idApartaDispo, fechaEntrada, fechaSalida);
}

/**
 * @brief GesRAE::reservar
 * @pre Comprobar que esta disponible
 * @param idEdificio
 * @param tipo
 * @param entrada
 * @param salida
 */
void GesRAE::reservar(Reserva reserva)
{
    reservasPorAnio[reserva.getFechaEntrada().getAnio()] ++;
    edificios[reserva.getIdEdificio() - 1].reservar(reserva);
}

int GesRAE::numReservaAnio(int anio)
{
    return this->reservasPorAnio[anio];
}








