#include <math.h>
#include <iostream>

#include "Objet.h"

using namespace std;
 
Objet::Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}

Objet::Objet(const Type& t, const unsigned int x, const unsigned int y){

    typeO = t;
    posO.x=x;
    posO.y=y;

}

Objet::~Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}
void Objet::setPos(const unsigned int x, const unsigned int y){
    posO.x = x;
    posO.y = y;
}

Vect2 Objet::getPos()const  {

    return posO;
}

Type Objet::getType()const  {

    return typeO;
}

void Objet:: setType(const Type & t )
{
    typeO=t;
}