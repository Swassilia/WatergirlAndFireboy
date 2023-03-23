#include "Objet.h"

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

Vect2 Objet::getPos()const  {

    return posO;
}

Type Objet::getType()const  {

    return typeO;
}