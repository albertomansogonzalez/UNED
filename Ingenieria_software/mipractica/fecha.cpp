#include "fecha.h"
#include <chrono>

Fecha::Fecha(){

}

Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int Fecha::getDia() const
{
    return this->dia;
}

int Fecha::getMes() const
{
    return this->mes;
}

int Fecha::getAnio() const
{
    return this->anio;
}

const std::string Fecha::getFecha() const
{
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

void Fecha::setDia(int dia)
{
    this->dia = dia;
}

void Fecha::setMes(int mes)
{
    this->mes = mes;
}

void Fecha::setAnio(int anio)
{
    this->anio = anio;
}

Fecha Fecha::calcularFechaFinal(Fecha dia, int duracion)
{
    std::chrono::year_month_day fechaInicial{std::chrono::year{dia.getAnio()},
                                              std::chrono::month{dia.getMes()},
                                              std::chrono::day{dia.getDia()}};
    std::chrono::sys_days fechaSys = fechaInicial;

    std::chrono::sys_days fechaFin = fechaSys + std::chrono::days(duracion);

    std::chrono::year_month_day resultado = fechaFin;

    Fecha fechaFinal (static_cast<int>(unsigned(resultado.day())), static_cast<int>(unsigned(resultado.month())), static_cast<int>(resultado.year()));

    return fechaFinal;
}
