#ifndef NEV_HPP_INCLUDED
#define NEV_HPP_INCLUDED
#include <fstream>
#include "ember.h"
#include "memtrace.h"

struct ListaElem{
    Ember emberek;
    ListaElem *kov;
    ListaElem(ListaElem *p=NULL) :kov(p) {}
};

class Tlista{
    ListaElem *eleje;
public:

    ///Visszaadja a lista elej�re mutat� pointert
    ListaElem* geteleje() {return eleje;}

    ///Be�ll�tja a lista elej�re mutat� pointert
    void seteleje(ListaElem *n) {eleje=n;}

    ///Ki�rja az adott ListaElemet
    void kiir(std::ostream &, ListaElem *n);

    ///Megkeresi az adott ListaElemet vezet�kn�v alapj�n
    void keres(std::string, Tlista& l);

    ///Felvesz egy �j ListaElemet a list�ba
    void ujadat(Ember e, Tlista& l);

    ///T�rli az adott ListaElemet
    void torles(Ember&, Tlista& l);

    ///Kilist�zza a lista elemeit
    void listazas(std::ostream &, Tlista& l);

    ///Ki�rja a f�jlba a list�t
    void file_ki(std::ofstream&, Tlista &l, char*);

    ///Beolvassa a f�jlb�l a list�ba az adatokat
    ListaElem* file_be(std::ifstream&, Tlista& l, char*);

    ~Tlista(){
        while(eleje!=NULL){
            ListaElem *tmp =eleje->kov;
            delete eleje;
            eleje=tmp;
        }
    }

};

#endif // NEV_HPP_INCLUDED
