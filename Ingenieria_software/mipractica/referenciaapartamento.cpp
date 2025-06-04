#include "referenciaapartamento.h"
#include <cstdio>

ReferenciaApartamento::ReferenciaApartamento() {}

ReferenciaApartamento::ReferenciaApartamento(std::string texto)
{
    //TODO evitar estilo C
    char letraTipo;
    if (std::sscanf(texto.c_str(), "APT%02d%c%02d", &this->idEdificio, &letraTipo, &this->idApartamento) == 3) {
        switch(letraTipo){
        case 'B':
            this->tipo = TipoApartamento::Basico;
            break;
        case 'N':
            this->tipo = TipoApartamento::Normal;
            break;
        case 'L':
            this->tipo = TipoApartamento::Lujo;
            break;
}
    } else {
        //TODO error
        //std::cout << "Error al parsear el texto.\n";
    }

}

ReferenciaApartamento::ReferenciaApartamento(TipoApartamento tipo, int idApartamento, int idEdificio)
{
    this->tipo = tipo;
    this->idApartamento = idApartamento;
    this->idEdificio = idEdificio;
}

std::string ReferenciaApartamento::getTexto() const
{
    std::string texto;
    char letraTipo;
    switch(tipo){
        case TipoApartamento::Basico: letraTipo = 'B'; break;
        case TipoApartamento::Normal: letraTipo = 'N'; break;
        case TipoApartamento::Lujo: letraTipo = 'L'; break;
    }
    char buffer[9];
    std::snprintf(buffer, sizeof(buffer), "APT%02d%c%02d", idEdificio, letraTipo, idApartamento);return texto;
}

const TipoApartamento& ReferenciaApartamento::getTipo() const
{
    return this->tipo;
}

int ReferenciaApartamento::getIdApartamento() const
{
    return this->idApartamento;
}

int ReferenciaApartamento::getIdEdificio() const
{
    return this->idEdificio;
}

void ReferenciaApartamento::setTipo(TipoApartamento tipo)
{
    this->tipo = tipo;
}

void ReferenciaApartamento::setIdApartamento(int id)
{
    this->idApartamento = id;
}

void ReferenciaApartamento::setIdEdificio(int id)
{
    this->idEdificio = id;
}
