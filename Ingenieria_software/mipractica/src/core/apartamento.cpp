#include "apartamento.h"

Apartamento::Apartamento(TipoApartamento tipo, int idApartamento) {
    referencia.setTipo(tipo);
    referencia.setIdApartamento(idApartamento);
}

std::vector<Reserva> Apartamento::getReservasMes(int mes, int anio) const
{
    std::vector<Reserva> reservasMes;

    for (const Reserva& reserva : reservas) {
        if ((reserva.getFechaEntrada().getMes() == mes && reserva.getFechaEntrada().getAnio() == anio)  //TODO, que pasa si la reserva ocupa varios meses
            || (reserva.getFechaSalida().getMes() == mes && reserva.getFechaSalida().getAnio() == anio)) {
            reservasMes.push_back(reserva);
        }
    }

    return reservasMes;
}

bool Apartamento::estaDisponible(Fecha entrada, Fecha salida) const
{
    //Mirar si el apartamento esta disponible entre 2 fechas
    for (const Reserva& reserva : reservas) {
        if (reserva.getFechaEntrada() <= salida && reserva.getFechaSalida() >= entrada){
        //if (Fecha::seSolapanRangoFechas(reserva.getFechaEntrada(), reserva.getFechaSalida(), entrada, salida)){
            return false;
        }
    }
    return true;
}

void Apartamento::addReserva(Reserva reserva)
{
    this->reservas.push_back(reserva);
}
