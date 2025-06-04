#ifndef RESERVA_H
#define RESERVA_H

#include "fecha.h"
#include "TiposComunes.h"
#include "referenciaapartamento.h"

class Reserva
{
public:
    Reserva();
    Reserva(int numReserva, int idEdificio,const char* nombreEdificio, TipoApartamento tipo,int idApartaDispo, Fecha fechaEntrada, Fecha fechaSalida);
    void setNumReserva(int numReserva);
    void setRefApartamento(char* refApartamento);
    void setFechaEntrada(const Fecha& fechaEntrada);
    void setFechaSalida(const Fecha& fechaSalida);
    void setDuracion(int duracion);
    void setIdEdificio(int id);
    void setidApartamento(int id);
    void setNombreEdificio(const char *nombre);
    void setTipoApartamento(TipoApartamento tipo);
    int getNumReserva() const;
    ReferenciaApartamento getRefApartamento() const;
    const char *getNombreEdificio() const;
    const Fecha& getFechaEntrada() const;
    const Fecha& getFechaSalida() const;
    int getDuracion() const;
    int getIdEdificio() const;
    int getIdApartamento() const;
    const TipoApartamento& getTipo() const;
private:
    /**
     * @brief numReserva Dentro de cada anio
     */
    int numReserva;
    char nombreEdificio [20];
    ReferenciaApartamento referencia;
    Fecha fechaEntrada;
    int duracion;
    Fecha fechaSalida;

};

#endif // RESERVA_H
