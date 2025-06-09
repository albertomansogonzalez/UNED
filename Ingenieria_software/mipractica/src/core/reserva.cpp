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

void Reserva::setIdApartamento(int id)
{
    this->referencia.setIdApartamento(id);
}

int Reserva::getNumReserva() const
{
    return this->numReserva;
}

ReferenciaApartamento Reserva::getRefApartamento() const
{
    return this->referencia;
}

std::string Reserva::getNombreEdificio() const
{
    return this->nombreEdificio;
}

Fecha Reserva::getFechaEntrada() const
{
    return this->fechaEntrada;
}

Fecha Reserva::getFechaSalida() const
{
    return this->fechaSalida;
}

int Reserva::getDuracion() const
{
    return this->duracion;
}

int Reserva::getIdEdificio() const
{
    return this->referencia.getIdEdificio();
}

int Reserva::getIdApartamento() const
{
    return this->referencia.getIdApartamento();
}

TipoApartamento Reserva::getTipo() const
{
    return this->referencia.getTipo();
}
