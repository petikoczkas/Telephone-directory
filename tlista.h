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

    ///Visszaadja a lista elejére mutató pointert
    ListaElem* geteleje() {return eleje;}

    ///Beállítja a lista elejére mutató pointert
    void seteleje(ListaElem *n) {eleje=n;}

    ///Kiírja az adott ListaElemet
    void kiir(std::ostream &, ListaElem *n);

    ///Megkeresi az adott ListaElemet vezetéknév alapján
    void keres(std::string, Tlista& l);

    ///Felvesz egy új ListaElemet a listába
    void ujadat(Ember e, Tlista& l);

    ///Törli az adott ListaElemet
    void torles(Ember&, Tlista& l);

    ///Kilistázza a lista elemeit
    void listazas(std::ostream &, Tlista& l);

    ///Kiírja a fájlba a listát
    void file_ki(std::ofstream&, Tlista &l, char*);

    ///Beolvassa a fájlból a listába az adatokat
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
