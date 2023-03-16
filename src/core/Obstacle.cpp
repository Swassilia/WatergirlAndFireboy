#include "Obstacle.h"

//Constructeur par defaut
Obstacle::Obstacle(){}

//Constructeur de la classe qui initialise le type de l'obstacle, et sa position grâce aux coordonées x et y en paramètre
Obstacle::Obstacle(const Type & t,unsigned int x, unsigned int y){ 
    pos=make_Vect2(x,y);
    dir=0;
    type_ob=t; 
}

//Destructeur de la classe Bonus
Obstacle::~Obstacle()
{
    pos=make_Vect2(0,0);
    dir=0;
    type_ob= Defaut;
}


Vect2 Obstacle::getPos()const {
    return pos;
}

Type Obstacle:: getType()const 
{
    return type_ob;
}

