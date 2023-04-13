#include <iostream>
#include "Personnage.h"
#include "Plateau.h"
#include "Jeu.h"
#include "Animation.h"
using namespace std;



int main(){
    Personnage p;
    Plateau pla;
    Jeu jeu;
    // cout<<b.getType()<<" "<<ob.getType()<<" "<<p.getPos().x<<endl;
    // jeu.testRegression_Jeu();
    // pla.testRegression_Pla();
    jeu.ActionAuto(pla);
    cout<<"test jeu"<<endl;

    return 0;
}