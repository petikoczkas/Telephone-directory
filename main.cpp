#include <iostream>
#include <string>
#include "tlista.h"
#include "test.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    setlocale(LC_ALL, "");
    Tlista lista;
    std::ifstream be;
    std::ofstream ki;
    char filenev[9]="adat.txt";
    lista.seteleje(lista.file_be(be, lista, filenev));
    char valasz;
    cout << "Uj adat felvetele(1)\nAdat torlese(2)\nAdatok kilistazasa(3)\nKereses(4)\nTeszteles(T)\nKilepes(*)\n\n";
    while(cin >> valasz){
        switch(valasz){
            case '1':{
                Nev ujn;
                Telszam ujt;
                Cim ujc;
                Ember uje;
                string adat;
                cout << "Vezeteknev: ";
                cin >> adat;
                ujn.setvez(adat);
                cout << "Keresztnev: ";
                cin >> adat;
                ujn.setkereszt(adat);
                cout << "Becenev: ";
                cin >> adat;
                ujn.setbece(adat);
                cout << "Munkahelyi szam: ";
                cin >> adat;
                ujt.setmunsz(adat);
                cout << "Privat szam: ";
                cin >> adat;
                cout << "Cim: ";
                ujt.setprivsz(adat);
                cin.ignore();
                getline(cin, adat);
                ujc.setcim(adat);
                uje.setneve(ujn);
                uje.settelszama(ujt);
                uje.setcime(ujc);
                lista.ujadat(uje, lista);
                cout << endl;
                break;
            }
            case '2':{
                cout << "Vezeteknev: ";
                string v,k;
                cin >> v;
                cout << "Keresztnev: ";
                cin >> k;
                ListaElem *p=lista.geteleje();
                bool s=false;
                while(p!=NULL && !s){
                    if(p->emberek.getneve().getvez()==v && p->emberek.getneve().getkereszt()==k) s=true;
                    else p=p->kov;
                }
                if(!s) cout << "\nNincs a keresesnek megfelelo elem\n";
                else{
                    lista.torles(p->emberek, lista);
                    cout << "\nA torles sikeres\n";
                }

                cout << endl;
                break;
                }
            case '3':{
                lista.listazas(cout, lista);
                cout << endl;
                break;
            }
            case '4':{
                cout << "Vezeteknev: ";
                string mit;
                cin >> mit;
                cout << endl;
                lista.keres(mit, lista);
                cout << endl;
                break;
            }
            case '*':{
                lista.file_ki(ki, lista, filenev);
                break;
            }
            case 'T':{
                teszt(); break;
            }
            default:{
                cout << "Hibas ertek\n" << endl; break;
            }
        }

        if(valasz=='*') break;
        cout << "\nUj adat felvetele(1)\nAdat torlese(2)\nAdatok kilistazasa(3)\nKereses(4)\nTeszteles(T)\nKilepes(*)\n\n";
    }
    return 0;
}
