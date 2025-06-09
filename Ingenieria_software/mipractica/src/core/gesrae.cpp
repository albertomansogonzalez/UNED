#include "gesrae.h"

GesRAE::GesRAE() {}

void GesRAE::aniadirEdificio(Edificio edificio)
{
    this->edificios[edificio.getIdEdificio() - 1] = edificio;
}

InfoEdificio GesRAE::getInfoEdificio(int id) const
{
    return edificios[id - 1].getInfoEdificio();
}

int GesRAE::numApartaDisponible(int idEdificio, TipoApartamento tipo, Fecha entrada, Fecha salida)
{
    return edificios[idEdificio - 1].numApartamentoDisponible(tipo, entrada, salida);
}

std::optional<Reserva> GesRAE::reservar(bool confirmacion, int idEdificio, TipoApartamento tipo, Fecha fechaEntrada, Fecha fechaSalida)
{
    //el gestor crea una proto-reserva, con algunos datos
    Reserva protoReserva(reservasPorAnio[fechaEntrada.getAnio()] + 1, idEdificio, edificios[idEdificio - 1].getNombre(), tipo, 0/*idApartamento lo rellena el edificio*/, fechaEntrada, fechaSalida);

    //TODO ¿que pasa si la fechaEntrada > fechaSalida??

    auto reserva = edificios[protoReserva.getIdEdificio() - 1].reservar(confirmacion, protoReserva);
    if (confirmacion && reserva){
        //si la reserva se ha cumplido
        reservasPorAnio[fechaEntrada.getAnio()]++;
    }

    return reserva;
}

int GesRAE::numReservaAnio(int anio)
{
    return this->reservasPorAnio[anio];
}

ResumenMensual GesRAE::obtenerResumenMensual(ReferenciaApartamento referencia, int mes, int anio)
{
    ResumenMensual resum;
    resum.reservas = edificios[referencia.getIdEdificio() - 1].obtenerReservasMes(referencia.getIdApartamento(), referencia.getTipo(), mes, anio);

    for (int i = 0; i < 31; i++){
        resum.diasReservados[i] = false;
    }
    resum.nReservados = 0;

    for (const Reserva& reserva: resum.reservas){
        //setea a reservado todos los dias de la reserva
        for (int i = reserva.getFechaEntrada().getDia(); i < reserva.getFechaEntrada().getDia() + reserva.getDuracion(); i++) {
            ++resum.nReservados;
            resum.diasReservados[i] = true;
        }
    }

    resum.nLibres = Fecha::diasDelMes(mes, anio) - resum.nReservados;

    return resum;
}








