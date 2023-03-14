#include "Obstacle.h"

//Constructeur par defaut
Obstacle::Obstacle(){}

//Constructeur de la classe qui initialise le type de l'obstacle, et sa position grâce aux coordonées x et y en paramètre
Obstacle::Obstacle(Type t,unsigned int x, unsigned int y){ 
    pos.x =x;
    pos.y =y;
    dir=0;
    type_ob=t; 
}

//Destructeur de la classe Bonus
Obstacle::~Obstacle()
{
    pos.x =0.0;
    pos.y =0.0;
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
void Obstacle::bougeAuto(const Plateau &p){ 
    int dx [4] = { 1, 0, -1, 0};
    int dy [4] = { 0, 1, 0, -1};
    int xtmp,ytmp;
    xtmp = pos.x + dx[dir];
    ytmp = pos.y + dy[dir];
    pos.x = xtmp;
    pos.y = ytmp;
}
