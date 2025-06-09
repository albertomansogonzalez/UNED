#ifndef RESERVA_H
#define RESERVA_H

#include "fecha.h"
#include "TiposComunes.h"
#include "referenciaapartamento.h"

class Reserva
{
public:
    Reserva();
    Reserva(int numReserva, int idEdificio,std::string nombreEdificio, TipoApartamento tipo,int idApartartamento, Fecha fechaEntrada, Fecha fechaSalida);
    void setIdApartamento(int id);
    int getNumReserva() const;
    ReferenciaApartamento getRefApartamento() const;
    std::string getNombreEdificio() const;
    Fecha getFechaEntrada() const;
    Fecha getFechaSalida() const;
    int getDuracion() const;
    int getIdEdificio() const;
    int getIdApartamento() const;
    TipoApartamento getTipo() const;
private:
    /**
     * @brief numReserva Dentro de cada anio
     */
    int numReserva;
    std::string nombreEdificio;
    ReferenciaApartamento referencia;
    Fecha fechaEntrada;
    int duracion;
    Fecha fechaSalida;

};

#endif // RESERVA_H
