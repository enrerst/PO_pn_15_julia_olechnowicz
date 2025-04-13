#ifndef KLASA_KALKULATOR_H
#define KLASA_KALKULATOR_H

#include <QObject>

class klasa_kalkulator : public QObject
{
    Q_OBJECT
public:
    explicit klasa_kalkulator(QObject *parent = nullptr);

    double oblicz(double a, double b, char op);  // było calculate
    void wyczysc();                             // było clear
    double pobierzPamiec() const;               // było getMemory

private:
    double pamiec = 0;                          // było mem
    bool pamiec_uzyta = false;                  // było mem_used

    double dodaj(double a, double b);           // było add
    double odejmij(double a, double b);         // było sub
    double pomnoz(double a, double b);          // było tim
    double podziel(double a, double b);         // było divide
    double modulo(double a, double b);          // było mod
};

#endif // CALCULATOR_H
