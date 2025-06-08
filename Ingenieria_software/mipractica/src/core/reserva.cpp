#include "reserva.h"
#include <cstring>
#include <stdio.h>

Reserva::Reserva() {}

Reserva::Reserva(int numReserva,int idEdificio,const char* nombreEdificio, TipoApartamento tipo,int idApartaDispo /*TODO revisar el nombre del parametro*/, Fecha fechaEntrada, Fecha fechaSalida)
{
    this->numReserva = numReserva;
    this->referencia.setIdEdificio(idEdificio);
    strcpy(this->nombreEdificio, nombreEdificio);
    this->referencia.setTipo(tipo);
    this->referencia.setIdApartamento(idApartaDispo);
    this->fechaEntrada = fechaEntrada;
    this->fechaSalida = fechaSalida;
    this->duracion = fechaEntrada.calcularDuracion(fechaSalida);
}

void Reserva::setNumReserva(int numReserva)
{
    this->numReserva = numReserva;
}

void Reserva::setFechaEntrada(const Fecha& fechaEntrada)
{
    this->fechaEntrada = fechaEntrada;
}

void Reserva::setFechaSalida(const Fecha& fechaSalida)
{
    this->fechaSalida = fechaSalida;
}

void Reserva::setIdEdificio(int id)
{
    this->referencia.setIdEdificio(id);
}

void Reserva::setidApartamento(int id)
{
    this->referencia.setIdApartamento(id);
}

void Reserva::setNombreEdificio(const char *nombre)
{
    strcmp(this->nombreEdificio, nombre);
}

void Reserva::setTipoApartamento(TipoApartamento tipo)
{
    this->referencia.setTipo(tipo);
}

int Reserva::getNumReserva() const
{
    return this->numReserva;
}

ReferenciaApartamento Reserva::getRefApartamento() const
{
    return this->referencia;
}

const char *Reserva::getNombreEdificio() const
{
    return this->nombreEdificio;
}

const Fecha& Reserva::getFechaEntrada() const
{
    return this->fechaEntrada;
}

const Fecha& Reserva::getFechaSalida() const
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

const TipoApartamento &Reserva::getTipo() const
{
    return this->referencia.getTipo();
}
