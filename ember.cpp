#include "ember.h"

bool Ember::operator!=(Ember &e){
    return(neve.getvez()!=e.neve.getvez()||
            neve.getkereszt()!=e.neve.getkereszt()||
            neve.getbece()!=e.neve.getbece()||
            telszama.getmunsz()!=e.telszama.getmunsz()||
            telszama.getprivsz()!=e.telszama.getprivsz()||
            cime.getcim()!=e.cime.getcim());
}
