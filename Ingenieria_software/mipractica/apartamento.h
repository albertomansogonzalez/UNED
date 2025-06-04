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
    bool disponible(Fecha entrada, Fecha salida) const;
    const TipoApartamento &getTipo() const;
    void addReserva(Reserva reserva);
    int getIdApartamento() const;
    const std::vector<Reserva> getReservas() const;
    /**
     * @brief getReservasMes Devuelve lista con reservas del mes
     * @param mes
     * @return
     */
    const std::vector<Reserva> getReservasMes(int mes, int anio) const;
private:
    ReferenciaApartamento referencia;
    std::vector<Reserva> reservas;
};

#endif // APARTAMENTO_H
