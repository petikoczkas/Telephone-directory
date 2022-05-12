#ifndef TELSZAM_HPP_INCLUDED
#define TELSZAM_HPP_INCLUDED
#include <iostream>
#include <string>
class Telszam{
private:
    std::string privsz;
    std::string munsz;
public:

    Telszam() {};

    Telszam(const char* priv, const char* mun): privsz(priv), munsz(mun) {}

    ///privát szám értékét adja vissza
    std::string getprivsz() const {return privsz;}

    ///privát szám értékét állítja be
    void setprivsz(std::string s) {privsz=s;}

    ///munkahelyi szám értékét adja vissza
    std::string getmunsz() const {return munsz;}

    ///munkahelyi szám értékét állítja be
    void setmunsz(std::string s) {munsz=s;}

    ~Telszam(){}
};

#endif // TELSZAM_HPP_INCLUDED
