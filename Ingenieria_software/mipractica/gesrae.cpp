#include "gesrae.h"

GesRAE::GesRAE() {}

void GesRAE::aniadirEdificio(Edificio edificio)
{
    this->edificios[edificio.getIdEdificio() - 1] = edificio;
}

InfoEdificio GesRAE::getInfoEdicicio(int id) const
{
    return edificios[id - 1].getInfoEdificio();
}

int GesRAE::numApartaDisponible(int idEdificio, TipoApartamento tipo, Fecha entrada, Fecha salida)
{
    return edificios[idEdificio - 1].numApartamentoDisponible(tipo, entrada, salida);
}

Reserva GesRAE::reservar(bool confirmacion, int idEdificio, TipoApartamento tipo, Fecha fechaEntrada, Fecha fechaSalida)
{
    //el gestor crea una proto-reserva, con algunos datos
    Reserva reserva(++reservasPorAnio[fechaEntrada.getAnio()], idEdificio, edificios[idEdificio - 1].getNombre(), tipo, 0/*idApartamento lo rellena el edificio*/, fechaEntrada, fechaSalida);
    return edificios[reserva.getIdEdificio() - 1].reservar(confirmacion, reserva);
}

int GesRAE::numReservaAnio(int anio)
{
    return this->reservasPorAnio[anio];
}

std::vector<Reserva> GesRAE::obtenerReservasMes(ReferenciaApartamento referencia, int mes, int anio)
{
    //TODO, primero devuelvo todas, da igual el mes. Luego limitar a solo ese mes
    return edificios[referencia.getIdEdificio() - 1].obtenerReservasMes(referencia.getIdApartamento(), referencia.getTipo(), mes, anio);

}








