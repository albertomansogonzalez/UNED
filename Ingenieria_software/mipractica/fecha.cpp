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

const std::string Fecha::toString() const
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

Fecha Fecha::calcularFechaFinal(int duracion) const
{
    std::chrono::year_month_day fechaInicial{std::chrono::year{anio},
                                             std::chrono::month{mes},
                                             std::chrono::day{dia}};
    std::chrono::sys_days fechaSys = fechaInicial;

    std::chrono::sys_days fechaFin = fechaSys + std::chrono::days(duracion);

    std::chrono::year_month_day resultado = fechaFin;

    Fecha fechaFinal (static_cast<int>(unsigned(resultado.day())), static_cast<int>(unsigned(resultado.month())), static_cast<int>(resultado.year()));

    return fechaFinal;
}

int Fecha::calcularDuracion(Fecha fechaSalida) const
{
    std::chrono::year_month_day fecha1 {std::chrono::year{this->getAnio()},
                                       std::chrono::month{this->getMes()},
                                        std::chrono::day{this->getDia()}};
    std::chrono::year_month_day fecha2 {std::chrono::year{fechaSalida.getAnio()},
                                        std::chrono::month{fechaSalida.getMes()},
                                        std::chrono::day{fechaSalida.getDia()}};

    std::chrono::sys_days dias1 = std::chrono::sys_days(fecha1);
    std::chrono::sys_days dias2 = std::chrono::sys_days(fecha2);

    std::chrono::days diferencia = dias2 - dias1;

    return diferencia.count();
}
