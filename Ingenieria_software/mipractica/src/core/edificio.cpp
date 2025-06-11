#include "edificio.h"
#include <cstring>
#include <iostream>

Edificio::Edificio() {
    idEdificio = -1; //-1 indica que los datos del edifico no estan rellenos
    nombre =  "";
    nBasicos = 0;
    nNormales = 0;
    nLujo = 0;
}

/**
 * @param idEdificio Valor entre 1 y 5 que identifica el edificio.
 */
Edificio::Edificio(int idEdificio, std::string nombre, std::size_t nBasicos, std::size_t nNormales, std::size_t nLujo)
{
    this->idEdificio = idEdificio;
    this->nombre = nombre;
    this->nBasicos = nBasicos;
    this->nNormales = nNormales;
    this->nLujo = nLujo;

    for (int i = 0 ; i < nBasicos; i++){
        apartamentos.push_back(Apartamento(TipoApartamento::Basico, i+1));
    }
    for (int i = 0 ; i < nNormales; i++){
        apartamentos.push_back(Apartamento(TipoApartamento::Normal, i+1));
    }
    for (int i = 0 ; i < nLujo; i++){
        apartamentos.push_back(Apartamento(TipoApartamento::Lujo, i+1));
    }
}

int Edificio::numApartamentoDisponible(TipoApartamento tipo, Fecha entrada, Fecha salida)
{
    int num = 0;
    for (const Apartamento& apartamento: apartamentos){
        if (apartamento.getTipo() == tipo && apartamento.estaDisponible(entrada, salida)){
            num++;
        }
    }
    return num;
}

std::optional<Reserva> Edificio::reservar(bool confirmacion, Reserva reserva)
{
    //se reserva el primer apartamento que se encuentre disponible
    for (Apartamento& apartamento: apartamentos){
        if (apartamento.getTipo() == reserva.getTipo() && apartamento.estaDisponible(reserva.getFechaEntrada(), reserva.getFechaSalida())){
            reserva.setIdApartamento(apartamento.getIdApartamento());
            if (confirmacion) apartamento.addReserva(reserva);
            return reserva;
        }
    }

    //si no hay reserva disponible
    return std::nullopt;
}

std::vector<Reserva> Edificio::obtenerReservasMes(int idApartamento, TipoApartamento tipo, int mes, int anio)
{
    //primero encontrar el apartamento
    for (const Apartamento& apartamento: apartamentos){
        if (apartamento.getIdApartamento() == idApartamento && apartamento.getTipo() == tipo){
            //dentro del apartamento, coger las reservas
            return apartamento.getReservasMes(mes, anio);
        }
    }

    std::cerr << "unreachable code\n";  //TODO revisar

}





