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

    ///vezetéknevet adja vissza
    std::string getvez() {return vez;}

    ///vezetéknév értékét állítja be
    void setvez(std::string s) {vez=s;}

    ///keresztnevet adja vissza
    std::string getkereszt() {return kereszt;}

    ///keresztnév értékét állítja be
    void setkereszt(std::string s) {kereszt=s;}

    ///becenevet adja vissza
    std::string getbece() {return bece;}

    ///becenév értékét állítja be
    void setbece(std::string s) {bece=s;}

    ~Nev() {}
    };

#endif // NEVEK_H_INCLUDED
