#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "TiposComunes.h"
#include "reserva.h"
#include <vector>

class Apartamento
{
public:
    Apartamento(TipoApartamento tipo, int idApartamento);
    bool disponible(Fecha entrada, Fecha salida) const;
    TipoApartamento getTipo() const;
    void addReserva(Reserva reserva);
    int getIdApartamento() const;
private:
    TipoApartamento tipo;
    int idApartamento;  //dentro de cada TipoApartamento
    std::vector<Reserva> reservas;
};

#endif // APARTAMENTO_H
