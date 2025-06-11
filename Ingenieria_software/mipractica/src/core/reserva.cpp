#include "reserva.h"
#include <cstring>
#include <stdio.h>

Reserva::Reserva() {}

Reserva::Reserva(int numReserva, int idEdificio, std::string nombreEdificio, TipoApartamento tipo, int idApartartamento, Fecha fechaEntrada, Fecha fechaSalida)
{
    this->numReserva = numReserva;
    this->referencia.setIdEdificio(idEdificio);
    this->nombreEdificio = nombreEdificio;
    this->referencia.setTipo(tipo);
    this->referencia.setIdApartamento(idApartartamento);
    this->fechaEntrada = fechaEntrada;
    this->fechaSalida = fechaSalida;
    this->duracion = fechaEntrada.calcularDuracion(fechaSalida);
}
