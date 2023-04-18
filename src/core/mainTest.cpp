#include <iostream>
#include "Personnage.h"
#include "Plateau.h"
#include "Jeu.h"
using namespace std;



int main(){
    Personnage p;
    Plateau pla;
    Jeu jeu;
    //pla.boueAuto();
    jeu.ActionAuto();
    cout<<"test jeu"<<endl;

    return 0;
}