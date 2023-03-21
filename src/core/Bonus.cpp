#include "Bonus.h"
using namespace std;

//Constructeur par défaut
Bonus::Bonus(){
    idB = Objet();
}

//Constructeur de la classe qui initialise le type du diamant, et sa position grâce aux coordonées x et y en paramètre
Bonus::Bonus( const Type& t, unsigned int posx, unsigned int posy){

    idB = Objet(t,posx,posy);

}

//Destructeur de la classe Bonus
Bonus::~Bonus(){
    
    
}
// Vect2 Bonus:: getPos()const
// {
//     return pos;
// }

// Type Bonus:: getType()
// {
//     return type_bon;
// }