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

    void setIdApartamento(int id) {referencia.setIdApartamento(id);}

    int getNumReserva() const {return numReserva;}

    ReferenciaApartamento getRefApartamento() const {return referencia;}

    std::string getNombreEdificio() const {return nombreEdificio;}

    Fecha getFechaEntrada() const {return fechaEntrada;}

    Fecha getFechaSalida() const {return fechaSalida;}

    int getDuracion() const {return duracion;}

    int getIdEdificio() const {return referencia.getIdEdificio();}

    int getIdApartamento() const {return referencia.getIdApartamento();}

    TipoApartamento getTipo() const {return referencia.getTipo();}

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
