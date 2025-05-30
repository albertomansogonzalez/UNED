#ifndef FECHA_H
#define FECHA_H

#include <string>

class Fecha
{
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    const std::string getFecha() const;
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);    
    static Fecha calcularFechaFinal(Fecha dia, int duracion);
private:
    int dia;
    int mes;
    int anio;
};

#endif // FECHA_H
