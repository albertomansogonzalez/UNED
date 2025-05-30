#include "edificio.h"
#include <cstring>

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

const std::vector<Apartamento> &Edificio::getApartamentos()
{
    return this->apartamentos;
}

int Edificio::getApartamentoDisponible(TipoApartamento tipo, Fecha entrada, Fecha salida)
{
    for (const Apartamento& apartamento: apartamentos){
        if (apartamento.getTipo() == tipo && apartamento.disponible(entrada, salida)){
            return apartamento.getIdApartamento();
        }
    }
    return -1;
}

void Edificio::reservar(Reserva reserva)
{
    for (Apartamento& apartamento: apartamentos){
        if (apartamento.getTipo() == reserva.getTipo() && apartamento.disponible(reserva.getFechaEntrada(), reserva.getFechaSalida())){
            apartamento.addReserva(reserva);
            //TODO exit??
        }
    }
}





