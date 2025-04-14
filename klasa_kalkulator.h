#ifndef KLASA_KALKULATOR_H
#define KLASA_KALKULATOR_H

#include <QObject>

class klasa_kalkulator : public QObject
{
    Q_OBJECT
public:
    explicit klasa_kalkulator(QObject *parent = nullptr);

    double oblicz(double a, double b, char op);  
    void wyczysc();                             
    double pobierzPamiec() const;              

private:
    double pamiec = 0;
    bool pamiec_uzyta = false;            

    double dodaj(double a, double b);     
    double odejmij(double a, double b);
    double pomnoz(double a, double b);
    double podziel(double a, double b);
    double modulo(double a, double b);
};

#endif 
