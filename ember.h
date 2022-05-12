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

    ///Nev oszt�ly �rt�k�t �ll�tja be
    void setneve(Nev n) {neve=n;}

    ///Telszam oszt�ly �rt�k�t �ll�tja be
    void settelszama(Telszam n) {telszama=n;}

    ///Cim oszt�ly �rt�k�t �ll�tja be
    void setcime(Cim n) {cime=n;}

    ///Nev oszt�lyt adja vissza
    Nev getneve() {return neve;}

    ///Telszam oszt�lyt adja vissza
    Telszam gettelszama() {return telszama;}

    ///Cim oszt�lyt adja vissza
    Cim getcime() {return cime;}

    ///Akkor t�r vissza igaz �rt�kkel ha a k�t Ember oszt�ly nem azonos
    bool operator!=(Ember &);

    ~Ember() {}
};



#endif // EMBER_HPP_INCLUDED
