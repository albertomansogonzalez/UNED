#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <vector>
#include "apartamento.h"
#include "reserva.h"

class Edificio
{
public:
    Edificio();
    Edificio(int idEdificio, char nombre [20], int nBasicos, int nNormales, int nLujo);
    void setIdEdificio(int idEdificio);
    void setNombre(char nombre [20]);
    void setNBasicos(int nBasicos);
    void setNNormales(int nNormales);
    void setNLujo(int nLujo);
    int getIdEdificio() const;
    const char* getNombre() const;
    int getNBasicos() const;
    int getNNormales() const;
    int getNLujo() const;
    const std::vector<Apartamento>& getApartamentos();
    int getApartamentoDisponible(TipoApartamento tipo, Fecha entrada, Fecha salida);
    void reservar(Reserva reserva);
private:
    int idEdificio;
    char nombre [20];
    int nBasicos;
    int nNormales;
    int nLujo;
    std::vector<Apartamento> apartamentos;
};

#endif // EDIFICIO_H
