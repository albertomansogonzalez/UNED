#ifndef REFERENCIAAPARTAMENTO_H
#define REFERENCIAAPARTAMENTO_H

#include "TiposComunes.h"
#include <string>

class ReferenciaApartamento
{
public:
    ReferenciaApartamento();

    ReferenciaApartamento(TipoApartamento tipo, int idEdificio, int idApartamento);

    TipoApartamento getTipo() const {return tipo;}

    int getIdApartamento() const {return idApartamento;}

    int getIdEdificio() const {return idEdificio;}

    void setTipo(TipoApartamento tipo) {this->tipo = tipo;}

    void setIdApartamento(int id){idApartamento = id;}

    void setIdEdificio(int id) {idEdificio = id;}

    /**
     * @brief parsear A partir de la string de referencia "APT02B03" guarda los datos
     * @param texto
     */
    void parsear(std::string texto);

    /**
     * @brief getTexto Devuelve la string de referencia, ej "APT02B03"
     * @return
     */
    std::string getTexto() const;

private:
    TipoApartamento tipo;

    /**
     * @brief idApartamento Cada tipo de apartamento tiene su conjunto de Ids
     */
    int idApartamento;

    int idEdificio;
};

#endif // REFERENCIAAPARTAMENTO_H
