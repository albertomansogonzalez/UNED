#include "reserva.h"
#include <cstring>
#include <stdio.h>

Reserva::Reserva() {}

Reserva::Reserva(int numReserva,int idEdificio,const char* nombreEdificio, TipoApartamento tipo,int idApartaDispo, Fecha fechaEntrada, Fecha fechaSalida)
{
    this->numReserva = numReserva;
    this->idEdificio = idEdificio;
    strcpy(this->nombreEdificio, nombreEdificio);
    this->tipo = tipo;
    this->fechaEntrada = fechaEntrada;
    this->fechaSalida = fechaSalida;
    this->duracion = duracion;

    char letraTipo;
    switch(tipo){
        case TipoApartamento::Basico: letraTipo = 'B'; break;
        case TipoApartamento::Normal: letraTipo = 'N'; break;
        case TipoApartamento::Lujo: letraTipo = 'L'; break;
    }
    sprintf(this->refApartamento, "APT%02d%c%02d", idEdificio, letraTipo, idApartaDispo);
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
    this->idEdificio = id;
}

void Reserva::setNombreEdificio(const char *nombre)
{
    strcmp(this->nombreEdificio, nombre);
}

void Reserva::setTipoApartamento(TipoApartamento tipo)
{
    this->tipo = tipo;
}

int Reserva::getNumReserva() const
{
    return this->numReserva;
}

const char *Reserva::getRefApartamento() const
{
    return this->refApartamento;
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

int Reserva::getIdEdificio() const
{
    return this->idEdificio;
}

const TipoApartamento &Reserva::getTipo() const
{
    return this->tipo;
}
