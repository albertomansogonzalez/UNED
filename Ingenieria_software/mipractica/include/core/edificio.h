#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <vector>
#include <string>
#include "apartamento.h"
#include "reserva.h"
#include <optional>

//DTO Data Transfer Objet
struct InfoEdificio{
    int idEdificio;
    std::string nombre;
    std::size_t nBasicos;
    std::size_t nNormales;
    std::size_t nLujo;
};

class Edificio
{
public:
    Edificio();

    /**
     * @brief Edificio
     * @param idEdificio ID entre 1 y 5
     * @param nombre
     * @param nBasicos Nº de apartaments basicos
     * @param nNormales Nº de apartaments normales
     * @param nLujo Nº de apartaments de lujo
     */
    Edificio(int idEdificio, std::string nombre, std::size_t nBasicos, std::size_t nNormales, std::size_t nLujo);

    int getIdEdificio() const{return idEdificio;}

    const std::string getNombre() const{return nombre;}

    InfoEdificio getInfoEdificio() const{ return {idEdificio, nombre, nBasicos, nNormales, nLujo};}

    /**
     * @brief numApartamentoDisponible
     * @param tipo
     * @param entrada
     * @param salida
     * @return Nº apartamentos disponibles
     */
    int numApartamentoDisponible(TipoApartamento tipo, Fecha entrada, Fecha salida);
    std::optional<Reserva> reservar(bool confirmacion, Reserva reserva);
    std::vector<Reserva> obtenerReservasMes(int idApartamento, TipoApartamento tipo, int mes, int anio);
private:
    int idEdificio;
    std::string nombre;
    std::size_t nBasicos;
    std::size_t nNormales;
    std::size_t nLujo;
    std::vector<Apartamento> apartamentos;
};

#endif // EDIFICIO_H
