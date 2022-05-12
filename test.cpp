#include "test.h"

void kiiras(Ember &emberek){
    cout << emberek.getneve().getvez() << " ";
    cout << emberek.getneve().getkereszt() << " ";
    cout << emberek.getneve().getbece() << ", ";
    cout << emberek.gettelszama().getmunsz() << ", ";
    cout << emberek.gettelszama().getprivsz() << ", ";
    cout << emberek.getcime().getcim() << std::endl;
}

void test_1(Ember e1, Ember e2, Tlista& l){
    ListaElem *p=l.geteleje();
    if(p->emberek!=e1 || p->kov->emberek!=e2) cout << "A fajlbol beolvasas sikertelen" << endl;
    else cout << "A fajlbol beolvasas sikeres" << endl;
}

void test_2(Ember e1, Ember e2, Ember e3, Tlista& l){
    l.ujadat(e3, l);
    ListaElem *p=l.geteleje();
    if(p->emberek!=e1 || p->kov->emberek!=e2 || p->kov->kov->emberek!=e3) cout << "Az uj adat felvetele sikertelen" << endl;
    else cout << "Az uj adat felvetele sikeres" << endl;
}

void test_3(Ember e1, Ember e2, Tlista& l){
    cout << "elvart:\n";
    kiiras(e1);
    kiiras(e2);
    cout << "\naktual:\n";
    l.listazas(cout, l);

}

void test_4(Ember e1, Ember e2, Tlista& l){
    l.torles(l.geteleje()->emberek, l);
    cout << "elvart:\n";
    kiiras(e2);
    cout << "\naktual:\n";
    l.listazas(cout, l);
}

void test_5(Ember e1, Ember e2, Tlista& l){
    cout << "elvart: ";
    kiiras(e2);
    cout << "\naktual: ";
    l.keres(e2.getneve().getvez(), l);
    cout << "\nHibas erteket adunk meg, valasz: ";
    l.keres("Naagy", l);
}

void test_6(Ember e1, Ember e2, Ember e3, Tlista& l, char* testfile){
    std::ifstream be;
    std::ofstream ki;
    l.ujadat(e3, l);
    l.file_ki(ki, l, testfile);
    l.seteleje(l.file_be(be, l, testfile));
    cout << "elvart:\n";
    kiiras(e1);
    kiiras(e2);
    kiiras(e3);
    cout << "\naktual:\n";
    l.listazas(cout, l);
}

int teszt(){
    Ember e1, e2, e3;
    Nev n1, n2, n3;
    Telszam t1, t2, t3;
    Cim c1, c2, c3;
    n1.setvez("Kiss");
    n1.setkereszt("Lajos");
    n1.setbece("Lali");
    t1.setmunsz("987");
    t1.setprivsz("787");
    c1.setcim("Szeged, Janos utca 13.");
    e1.setneve(n1);
    e1.settelszama(t1);
    e1.setcime(c1);

    n2.setvez("Nagy");
    n2.setkereszt("Erik");
    n2.setbece("Nagyi");
    t2.setmunsz("789");
    t2.setprivsz("987");
    c2.setcim("Debrecen, Arpad ut 12.");
    e2.setneve(n2);
    e2.settelszama(t2);
    e2.setcime(c2);

    n3.setvez("Hombar");
    n3.setkereszt("Henrietta");
    n3.setbece("Heni");
    t3.setmunsz("123");
    t3.setprivsz("321");
    c3.setcim("Isaszeg, Jozsef Attila utca 67.");
    e3.setneve(n3);
    e3.settelszama(t3);
    e3.setcime(c3);

    Tlista l;
    std::ifstream be;
    char testfile[9]="test.txt";
    l.seteleje(l.file_be(be, l, testfile));
    bool kilep=false;
    while(!kilep){
    try {
    char tst;
      cout << "\nTest1(1)\nTest2(2)\nTest3(3)\nTest4(4)\nTest5(5)\nTest6(6)\nKilepes(*)\n" << endl;
      cin >> tst;
      switch (tst) {
        case '1':{
            test_1(e1, e2, l);
            l.~Tlista();
            break;
        }

        case '2':{
            test_2(e1, e2, e3, l);
            l.~Tlista();
            break;
        }

        case '3':{
            test_3(e1, e2, l);
            l.~Tlista();
            break;
        }

        case '4':{
            test_4(e1, e2, l);
            l.~Tlista();
            break;
        }

        case '5':{
            test_5(e1, e2, l);
            l.~Tlista();
            break;
        }

        case '6':{
            test_6(e1, e2, e3, l, testfile);
            break;
            }

        case '*':{
            kilep=true;
            l.~Tlista();
            break;
        }

        default: cout << "Hibas ertek" << endl;
      }
      l.seteleje(l.file_be(be, l, testfile));
      if(l.geteleje()->kov->kov!=NULL){
        std::ofstream ki;
        l.torles(e3, l);
        l.file_ki(ki, l, testfile);
        }
    }

    catch(std::exception& e){
        std::cerr << e.what() << endl;
    }
    }
return 0;
}
