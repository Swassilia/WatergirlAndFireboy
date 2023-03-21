#include <cassert>
#include <cstddef>
#include "Obstacle.h"


//Constructeur par defaut
Obstacle::Obstacle(){
    
    idO = Objet();
}

//Constructeur de la classe qui initialise le type de l'obstacle, et sa position grâce aux coordonées x et y en paramètre
Obstacle::Obstacle(const Type & t,unsigned int x, unsigned int y){ 
    assert(x>=0 && y>=0);
    idO= Objet(t,x,y);
    dir=0; 
}

//Destructeur de la classe Bonus
Obstacle::~Obstacle()
{
    dir=0;
    idO=~Objet();
}

// //Assesseur: récupère la position 
// Vect2 Obstacle::getPos()const {
//     return pos;
// }
// //Assesseur: récupère la Type
// Type Obstacle:: getType()const 
// {
//     return type_ob;
// }

