#include "klasa_kalkulator.h"
#include <stdexcept>

klasa_kalkulator::klasa_kalkulator(QObject *parent) : QObject(parent){}

double klasa_kalkulator::dodaj(double a, double b) {
    return a + b;
}

double klasa_kalkulator::odejmij(double a, double b) {
    return a - b;
}

double klasa_kalkulator::pomnoz(double a, double b) {
    return a * b;
}

double klasa_kalkulator::podziel(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Dzielenie przez zero!");
    }
    return a / b;
}

double klasa_kalkulator::modulo(double a, double b) {
    return a - static_cast<int>(a / b) * b;
}

void klasa_kalkulator::wyczysc() {
    pamiec = 0;
    pamiec_uzyta = false;
}

double klasa_kalkulator::pobierzPamiec() const {
    return pamiec;
}

double klasa_kalkulator::oblicz(double a, double b, char op) {
    switch(op) {
    case '+': pamiec = dodaj(a, b); break;
    case '-': pamiec = odejmij(a, b); break;
    case '*': pamiec = pomnoz(a, b); break;
    case '/': pamiec = podziel(a, b); break;
    case '%': pamiec = modulo(a, b); break;
    default: throw std::runtime_error("Nieznany operator!");
    }

    pamiec_uzyta = true;
    return pamiec;
}
