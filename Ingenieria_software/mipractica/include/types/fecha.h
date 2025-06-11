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
    bool operator<=(const Fecha &other) const;
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    const std::string toString() const;
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    Fecha calcularFechaFinal(int duracion) const;
    int calcularDuracion(Fecha fechaSalida) const;

    /**
     * @brief seSolapanRangoFechas Dado 2 rangos de fechas, dice si se solapan
     *
     * Dado el rango A: (inicioA, finA) y el rango B: (inicioB, finB),
     * se solapan si (inicioA <= finB) && (finA => inicioB).
     *
     * @param inicioA Fecha de inicio del rango A
     * @param finA Fecha de fin del rango A
     * @param inicioB Fecha de inicio del rango B
     * @param finB Fecha de fin del rango B
     * @return
     */
    static bool seSolapanRangoFechas(Fecha inicioA, Fecha finA, Fecha inicioB, Fecha finB);

    static bool esBisiesto(int anio);
    static int diasDelMes(int mes, int anio);
    /**
     * @brief diaDeLaSemana Fórmula de Zeller
     * @param dia
     * @param mes
     * @param anio
     * @return 0=sabado, 1=domingo, 2=lunes, 3=martes, 4=miercoles, 5=jueves, 6=viernes
     */
    static int diaDeLaSemana(int dia, int mes, int anio);

    static std::string nombreMes(int mes);
private:
    int dia;
    int mes;
    int anio;
};

#endif // FECHA_H
