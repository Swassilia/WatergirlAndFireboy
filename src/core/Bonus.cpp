#include "Bonus.h"
#include <iostream>
#include <time.h>
using namespace std;

Bonus::Bonus( unsigned int posx, unsigned int posy){

    diamantE= DiamantEau;    
    diamantF= DiamantFeu;

    pos_E.x=0.0;
    pos_E.y=0.0;

    pos_F.x= 0.0;
    pos_F.y=0.0;
    
    }

Bonus::~Bonus(){
    
    diamantE = defaut;
    diamantF = defaut;

    pos_E.x=0.0;
    pos_E.y=0.0;

    pos_F.x=0.0;
    pos_F.y=0.0;
    
}