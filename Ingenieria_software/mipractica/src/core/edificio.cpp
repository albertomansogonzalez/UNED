#include "edificio.h"
#include <cstring>
#include <iostream>

Edificio::Edificio() {
    this->idEdificio = -1;
    strcpy(this->nombre, "");
    this->nBasicos = 0;
    this->nNormales = 0;
    this->nLujo = 0;
}

/**
 * @param idEdificio Valor entre 1 y 5 que identifica el edificio.
 */
Edificio::Edificio(int idEdificio, char nombre[], int nBasicos, int nNormales, int nLujo)
{
    this->idEdificio = idEdificio;
    strcpy(this->nombre, nombre);
    this->nBasicos = nBasicos;
    this->nNormales = nNormales;
    this->nLujo = nLujo;

    for (int i = 0 ; i < nBasicos; i++){
        this->apartamentos.push_back(Apartamento(TipoApartamento::Basico, i+1));
    }
    for (int i = 0 ; i < nNormales; i++){
        this->apartamentos.push_back(Apartamento(TipoApartamento::Normal, i+1));
    }
    for (int i = 0 ; i < nLujo; i++){
        this->apartamentos.push_back(Apartamento(TipoApartamento::Lujo, i+1));
    }
}

void Edificio::setIdEdificio(int idEdificio)
{
    this->idEdificio = idEdificio;
}

void Edificio::setNombre(char nombre [20])
{
    strcpy(nombre, this->nombre);
}

void Edificio::setNBasicos(int nBasicos)
{
    this->nBasicos = nBasicos;
}

void Edificio::setNNormales(int nNormales)
{
    this->setNNormales(nNormales);
}

void Edificio::setNLujo(int nLujo)
{
    this->nLujo = nLujo;
}

int Edificio::getIdEdificio() const
{
    return this->idEdificio;
}

const char* Edificio::getNombre() const
{
    return this->nombre;
}

int Edificio::getNBasicos() const
{
    return this->nBasicos;
}

int Edificio::getNNormales() const
{
    return this->nNormales;
}

int Edificio::getNLujo() const
{
    return this->nLujo;
}

InfoEdificio Edificio::getInfoEdificio() const
{
    InfoEdificio infoEdificio;
    infoEdificio.idEdificio = this->idEdificio;
    strcpy(infoEdificio.nombre, this->nombre);
    infoEdificio.nBasicos = this->nBasicos;
    infoEdificio.nNormales = this->nNormales;
    infoEdificio.nLujo = this->nLujo;

    return infoEdificio;

}

const std::vector<Apartamento> &Edificio::getApartamentos()
{
    return this->apartamentos;
}

int Edificio::numApartamentoDisponible(TipoApartamento tipo, Fecha entrada, Fecha salida)
{
    int num = 0;
    for (const Apartamento& apartamento: apartamentos){
        if (apartamento.getTipo() == tipo && apartamento.disponible(entrada, salida)){
            num++;
            //return apartamento.getIdApartamento();
        }
    }
    return num;
}

std::optional<Reserva> Edificio::reservar(bool confirmacion, Reserva reserva)
{
    //se reserva el primer apartamento que se encuentre disponible
    for (Apartamento& apartamento: apartamentos){
        if (apartamento.getTipo() == reserva.getTipo() && apartamento.disponible(reserva.getFechaEntrada(), reserva.getFechaSalida())){
            reserva.setidApartamento(apartamento.getIdApartamento());
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

    std::cerr << "unreachable code\n";

}





