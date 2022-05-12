#ifndef NEVEK_H_INCLUDED
#define NEVEK_H_INCLUDED
#include <iostream>
#include <string>

class Nev{
private:
    std::string vez;
    std::string kereszt;
    std::string bece;
public:

    Nev() {}

    Nev(const char* v, const char* k, const char* b) :vez(v), kereszt(k), bece(b) {}

    ///vezet�knevet adja vissza
    std::string getvez() {return vez;}

    ///vezet�kn�v �rt�k�t �ll�tja be
    void setvez(std::string s) {vez=s;}

    ///keresztnevet adja vissza
    std::string getkereszt() {return kereszt;}

    ///keresztn�v �rt�k�t �ll�tja be
    void setkereszt(std::string s) {kereszt=s;}

    ///becenevet adja vissza
    std::string getbece() {return bece;}

    ///becen�v �rt�k�t �ll�tja be
    void setbece(std::string s) {bece=s;}

    ~Nev() {}
    };

#endif // NEVEK_H_INCLUDED
