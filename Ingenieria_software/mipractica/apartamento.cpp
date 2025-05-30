#include "apartamento.h"

Apartamento::Apartamento(TipoApartamento tipo, int idApartamento) {
    this->tipo = tipo;
    this->idApartamento = idApartamento;

}

bool Apartamento::disponible(Fecha entrada, Fecha salida) const
{
    //TODO
    return true;
}

TipoApartamento Apartamento::getTipo() const
{
    return this->tipo;
}

void Apartamento::addReserva(Reserva reserva)
{
    this->reservas.push_back(reserva);
}

int Apartamento::getIdApartamento() const
{
    return this->idApartamento;
}
