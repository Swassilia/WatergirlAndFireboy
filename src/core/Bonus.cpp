#include "Bonus.h"
//#include <iostream>
//#include <time.h>
using namespace std;

Bonus::Bonus( Type t, unsigned int posx, unsigned int posy){

    pos.x=posx;
    pos.y=posy;
    int i =(rand ()% 4 ) + 2 //pas sure du random
    switch (i)
    {
    case 2: 
        type_bon= DiamantEau;
        break;
    case 3:
        type_bon= DiamantFeu;
        break;
    default:
        break;
    }

Bonus::~Bonus(){
    
    type_bon= Defaut;

    pos.x=0.0;
    pos.y=0.0;
    
}