#include "tlista.h"

    void Tlista::kiir(std::ostream &os, ListaElem *p){
        os << p->emberek.getneve().getvez() << " ";
        os << p->emberek.getneve().getkereszt() << " ";
        os << p->emberek.getneve().getbece() << ", ";
        os << p->emberek.gettelszama().getmunsz() << ", ";
        os << p->emberek.gettelszama().getprivsz() << ", ";
        os << p->emberek.getcime().getcim() << std::endl;
    }

    void Tlista::keres(std::string mit, Tlista& l){
        ListaElem *p;
        int db=0;
        for(p=l.geteleje(); p!=NULL; p=p->kov){
            if(p->emberek.getneve().getvez()==mit){
                l.kiir(std::cout, p);
                db++;
            }
        }
        if(db==0) std::cout << "Nincs a keresesnek megfelelo elem\n";
    }

    void Tlista::ujadat(Ember e, Tlista& l){
        ListaElem *uj;
        uj=new ListaElem;
        uj->emberek=e;
        ListaElem *mozgo;
        mozgo=l.geteleje();
        while(mozgo->kov!=NULL){
            mozgo=mozgo->kov;
        }
        mozgo->kov=uj;
        uj->kov=NULL;
    }

    void Tlista::torles(Ember& e, Tlista& l){
        ListaElem *lemarado=NULL;
        ListaElem *mozgo=l.geteleje();
        while(mozgo!=NULL && mozgo->emberek!=e){
            lemarado=mozgo;
            mozgo=mozgo->kov;
        }
        if(lemarado==NULL){
            ListaElem *ujeleje=mozgo->kov;
            delete mozgo;
            l.seteleje(ujeleje);
        }
        else{
            lemarado->kov=mozgo->kov;
            delete mozgo;
        }
    }

    void Tlista::listazas(std::ostream &os, Tlista& l){
        ListaElem *p;
        p=l.geteleje();
        while(p!=NULL){
            l.kiir(os, p);
            p=p->kov;
        }
    }

    void Tlista::file_ki(std::ofstream& ki, Tlista &l, char* filenev){
        ki.open(filenev);
        if(!ki.is_open()) throw "Nem sikerült a fajlt megnyitni";
        ListaElem *mozgo;
        for(mozgo=l.geteleje(); mozgo->kov!=NULL; mozgo=mozgo->kov){
            ki << mozgo->emberek.getneve().getvez() << " ";
            ki << mozgo->emberek.getneve().getkereszt() << " ";
            ki << mozgo->emberek.getneve().getbece() << " ";
            ki << mozgo->emberek.gettelszama().getmunsz() << " ";
            ki << mozgo->emberek.gettelszama().getprivsz() << " ";
            ki << mozgo->emberek.getcime().getcim() << std::endl;
        }
        ki << mozgo->emberek.getneve().getvez() << " ";
        ki << mozgo->emberek.getneve().getkereszt() << " ";
        ki << mozgo->emberek.getneve().getbece() << " ";
        ki << mozgo->emberek.gettelszama().getmunsz() << " ";
        ki << mozgo->emberek.gettelszama().getprivsz() << " ";
        ki << mozgo->emberek.getcime().getcim();
        ki.close();
        l.~Tlista();
    }

    ListaElem* Tlista::file_be(std::ifstream& be, Tlista& l, char* filenev){
        be.open(filenev);
        if(!be.is_open()) throw "Nem sikerült a fajlt megnyitni";
        std::string a;
        Nev n;
        Telszam t;
        Cim c;
        Ember e;
        be >> a;
        n.setvez(a);
        be >> a;
        n.setkereszt(a);
        be >> a;
        n.setbece(a);
        be >> a;
        t.setmunsz(a);
        be >> a;
        t.setprivsz(a);
        be.ignore();
        std::getline(be, a);
        c.setcim(a);
        e.setneve(n);
        e.settelszama(t);
        e.setcime(c);
        ListaElem *elem;
        elem=new ListaElem;
        elem->emberek=e;
        elem->kov=NULL;
        l.seteleje(elem);
        while(!(be.eof())){
            be >> a;
            n.setvez(a);
            be >> a;
            n.setkereszt(a);
            be >> a;
            n.setbece(a);
            be >> a;
            t.setmunsz(a);
            be >> a;
            t.setprivsz(a);
            be.ignore();
            std::getline(be, a);
            c.setcim(a);
            e.setneve(n);
            e.settelszama(t);
            e.setcime(c);
            l.ujadat(e, l);
        }
        be.close();
        return l.geteleje();
    }
