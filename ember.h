#ifndef EMBER_HPP_INCLUDED
#define EMBER_HPP_INCLUDED
#include <iostream>
#include <string>
#include "nev.h"
#include "telszam.h"
#include "cim.h"


class Ember{
private:
    Nev neve;
    Telszam telszama;
    Cim cime;
public:

    Ember() {}

    Ember(Nev n, Telszam t, Cim c): neve(n), telszama(t), cime(c) {}

    ///Nev osztály értékét állítja be
    void setneve(Nev n) {neve=n;}

    ///Telszam osztály értékét állítja be
    void settelszama(Telszam n) {telszama=n;}

    ///Cim osztály értékét állítja be
    void setcime(Cim n) {cime=n;}

    ///Nev osztályt adja vissza
    Nev getneve() {return neve;}

    ///Telszam osztályt adja vissza
    Telszam gettelszama() {return telszama;}

    ///Cim osztályt adja vissza
    Cim getcime() {return cime;}

    ///Akkor tér vissza igaz értékkel ha a két Ember osztály nem azonos
    bool operator!=(Ember &);

    ~Ember() {}
};



#endif // EMBER_HPP_INCLUDED
