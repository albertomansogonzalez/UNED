#include "fecha.h"
#include <chrono>

Fecha::Fecha(){

}

Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

bool Fecha::operator<(const Fecha& otra) const {
    if (anio < otra.anio) return true;
    if (anio > otra.anio) return false;

    // Si mismo año, comparar meses
    if (mes < otra.mes) return true;
    if (mes > otra.mes) return false;

    // Si mismo mes, comparar días
    return dia < otra.dia;
}

bool Fecha::operator==(const Fecha &otra) const
{
    return (dia == otra.dia && mes == otra.mes && anio == otra.anio);
}

bool Fecha::operator>(const Fecha &otra) const
{
    return otra < *this;  // Es decir, a > b <=> b < a
}

bool Fecha::operator>=(const Fecha &otra) const
{
    return !(*this < otra);
}

bool Fecha::operator<=(const Fecha &other) const
{
    return !(*this > other);
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

    return diferencia.count() + 1; //+1 para incluir tanto dia de entrada como el de salida
}

bool Fecha::esBisiesto(int anio)
{
    return (anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0);
}

int Fecha::diasDelMes(int mes, int anio)
{
    switch (mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return esBisiesto(anio) ? 29 : 28;
    default:
        return 0;
    }
}

int Fecha::diaDeLaSemana(int dia, int mes, int anio)
{
    if (mes < 3) {
        mes += 12;
        anio--;
    }
    int K = anio % 100;
            int J = anio / 100;
          int h = (dia + 13*(mes+1)/5 + K + K/4 + J/4 + 5*J) % 7;
            return h;
}

std::string Fecha::nombreMes(int mes)
{
    switch(mes){
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Septiembre";
        case 10: return "Octubre";
        case 11: return "Noviembre";
        case 12: return "Diciembre";
    }
}

