#include "referenciaapartamento.h"
#include <cstdio>
#include <stdexcept>

ReferenciaApartamento::ReferenciaApartamento() {}


ReferenciaApartamento::ReferenciaApartamento(TipoApartamento tipo, int idEdificio, int idApartamento)
{
    this->tipo = tipo;
    this->idApartamento = idApartamento;
    this->idEdificio = idEdificio;
}

void ReferenciaApartamento::parsear(std::string texto)
{
    //TODO evitar estilo C
    char letraTipo;
    if (std::sscanf(texto.c_str(), "APT%02d%c%02d", &this->idEdificio, &letraTipo, &this->idApartamento) == 3) {
        this->tipo = charToTipoApartamento(letraTipo);
    } else {
        throw std::invalid_argument("Formato de referencia invalido");
    }
}

std::string ReferenciaApartamento::getTexto() const
{
    char letraTipo = tipoApartamentoToChar(this->tipo);
    char buffer[9];
    std::snprintf(buffer, sizeof(buffer), "APT%02d%c%02d", idEdificio, letraTipo, idApartamento);

    return std::string(buffer);
}
