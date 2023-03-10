#include "Bonus.h"
//#include <iostream>
//#include <time.h>
using namespace std;

Bonus::Bonus( unsigned int posx, unsigned int posy){

    diamantE= DiamantEau;    
    diamantF= DiamantFeu;

    pos_E.x=posx;
    pos_E.y=posy;

    pos_F.x= posx+1; //pour qu'il soit quand même un peu décalé de l'autre diamant
    pos_F.y=posy+1;
    
    }

Bonus::~Bonus(){
    
    diamantE = defaut;
    diamantF = defaut;

    pos_E.x=0.0;
    pos_E.y=0.0;

    pos_F.x=0.0;
    pos_F.y=0.0;
    
}