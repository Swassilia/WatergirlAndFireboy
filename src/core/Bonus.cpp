#include "Bonus.h"
using namespace std;

//Constructeur par défaut
Bonus::Bonus(){}

//Constructeur de la classe qui initialise le type du diamant, et sa position grâce aux coordonées x et y en paramètre
Bonus::Bonus( Type t, unsigned int posx, unsigned int posy){

    pos.x=posx;
    pos.y=posy;
    type_bon=t;

}

//Destructeur de la classe Bonus
Bonus::~Bonus(){
    
    type_bon= Defaut;
    pos.x=0.0;
    pos.y=0.0;
    
}
Vect2 Bonus:: getPos()
{
    return pos;
}

Type Bonus:: getType()
{
    return type_bon;
}