#ifndef RESERVA_H
#define RESERVA_H

#include "fecha.h"
#include "TiposComunes.h"

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
    const char* getRefApartamento() const;
    const char *getNombreEdificio() const;
    const Fecha& getFechaEntrada() const;
    const Fecha& getFechaSalida() const;
    int getDuracion() const;
    int getIdEdificio() const;
    int getIdApartamento() const;
    const TipoApartamento& getTipo() const;
private:
    int numReserva;
    int idEdificio;
    char nombreEdificio [20];
    int idApartamento;
    char refApartamento [8];
    TipoApartamento tipo;
    Fecha fechaEntrada;
    int duracion;
    Fecha fechaSalida;

};

#endif // RESERVA_H
