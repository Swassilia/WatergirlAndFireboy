#include "Objet.h"

Objet::Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}

Objet::Objet(Type t, const unsigned int x, const unsigned int y){

    typeO = t;
    posO.x=x;
    posO.y=y;

}

Objet::~Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}

Vect2 getPos() const {
    return posO;
}

Type getType() const {
    return typeO;
}