#ifndef FECHA_H
#define FECHA_H

#include <string>

class Fecha
{
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    bool operator<(const Fecha& otra) const;
    bool operator==(const Fecha& otra) const;
    bool operator>(const Fecha& otra) const;
    bool operator>=(const Fecha& otra) const;
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    const std::string toString() const;
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    Fecha calcularFechaFinal(int duracion) const;
    int calcularDuracion(Fecha fechaSalida) const;
private:
    int dia;
    int mes;
    int anio;
};

#endif // FECHA_H
