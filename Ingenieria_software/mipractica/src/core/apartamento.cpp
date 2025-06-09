#include "apartamento.h"

Apartamento::Apartamento(TipoApartamento tipo, int idApartamento) {
    this->referencia.setTipo(tipo);
    this->referencia.setIdApartamento(idApartamento);
}

bool Apartamento::disponible(Fecha entrada, Fecha salida) const
{
    //Mirar si el apartamento esta disponible entre 2 fechas
    for (const Reserva& reserva : reservas) {
        //hay colision si: (A1 <= B2) && (A2 => B1);
        if (reserva.getFechaEntrada() <= salida && reserva.getFechaSalida() >= entrada) {
            return false;
        }
    }
    return true;
}

TipoApartamento Apartamento::getTipo() const
{
    return this->referencia.getTipo();
}

int Apartamento::getIdApartamento() const
{
    return this->referencia.getIdApartamento();
}

const std::vector<Reserva> Apartamento::getReservas() const
{
    return this->reservas;
}

const std::vector<Reserva> Apartamento::getReservasMes(int mes, int anio) const
{
    std::vector<Reserva> reservasMes;

    for (const Reserva& reserva : reservas) {
        if ((reserva.getFechaEntrada().getMes() == mes && reserva.getFechaEntrada().getAnio() == anio)
            || (reserva.getFechaSalida().getMes() == mes && reserva.getFechaSalida().getAnio() == anio)) {
            reservasMes.push_back(reserva);
        }
    }

    return reservasMes;
}

void Apartamento::addReserva(Reserva reserva)
{
    this->reservas.push_back(reserva);
}
