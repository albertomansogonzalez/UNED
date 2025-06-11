#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "TiposComunes.h"
#include "reserva.h"
#include "referenciaapartamento.h"
#include <vector>

class Apartamento
{
public:
    Apartamento(TipoApartamento tipo, int idApartamento);

    TipoApartamento getTipo() const {return referencia.getTipo();}

    int getIdApartamento() const{return referencia.getIdApartamento();}

    /**
     * @brief getReservas Devuelve toda la lista de reservas del apartamento
     * @return Lista de reservas del apartamento
     */
    const std::vector<Reserva> &getReservas() const{return reservas;}

    /**
     * @brief getReservasMes Devuelve lista con las reservas que tiene el apartamento ese mes
     * @param mes
     * @return Lista de reservas del apartamento en ese mes/anio
     */
    std::vector<Reserva> getReservasMes(int mes, int anio) const;

    /**
     * @brief estaDisponible Consultar disponibilidad entre 2 fechas
     * @param entrada
     * @param salida
     * @return True si esta disponible
     */
    bool estaDisponible(Fecha entrada, Fecha salida) const;

    /**
     * @brief addReserva Aniade una reserva al apartamento
     * @param reserva
     */
    void addReserva(Reserva reserva);

private:
    /**
     * @brief referencia Identificador de cada apartamento
     */
    ReferenciaApartamento referencia;

    /**
     * @brief reservas Lista de todas las reservas del apartamento
     */
    std::vector<Reserva> reservas;
};

#endif // APARTAMENTO_H
