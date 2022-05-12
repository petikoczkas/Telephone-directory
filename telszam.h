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

    ///priv�t sz�m �rt�k�t adja vissza
    std::string getprivsz() const {return privsz;}

    ///priv�t sz�m �rt�k�t �ll�tja be
    void setprivsz(std::string s) {privsz=s;}

    ///munkahelyi sz�m �rt�k�t adja vissza
    std::string getmunsz() const {return munsz;}

    ///munkahelyi sz�m �rt�k�t �ll�tja be
    void setmunsz(std::string s) {munsz=s;}

    ~Telszam(){}
};

#endif // TELSZAM_HPP_INCLUDED
