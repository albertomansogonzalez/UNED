#ifndef REFERENCIAAPARTAMENTO_H
#define REFERENCIAAPARTAMENTO_H

#include "TiposComunes.h"
#include <string>

class ReferenciaApartamento
{
public:
    ReferenciaApartamento();
    ReferenciaApartamento(TipoApartamento tipo, int idEdificio, int idApartamento);
    void parsear(std::string texto);
    std::string getTexto() const;
    const TipoApartamento &getTipo() const;
    int getIdApartamento() const;
    int getIdEdificio() const;
    void setTipo(TipoApartamento tipo);
    void setIdApartamento(int id);
    void setIdEdificio(int id);
private:
    TipoApartamento tipo;
    /**
     * @brief idApartamento Cada tipo de apartamento tiene su conjunto de Ids
     */
    int idApartamento;
    int idEdificio;
};

#endif // REFERENCIAAPARTAMENTO_H
