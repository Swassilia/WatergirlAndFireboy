#include <math.h>
#include <iostream>

#include "Objet.h"

using namespace std;

//Constructeur par défaut de l'objet qui initialise le type de Objet à "Defaut" et la position à 0
Objet::Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}

//Constructeur par copie de l'objet qui initialise les données membres avec les paramètres
Objet::Objet(const Type& t, const unsigned int x, const unsigned int y){

    typeO = t;
    posO.x=x;
    posO.y=y;

}

//Destructeur de l'Objet 
Objet::~Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}

//Mutateur de l'Objet pour redéfinit la position de l'objet avec les valeurs passées en paramètre
void Objet::setPos(const unsigned int x, const unsigned int y){
    posO.x = x;
    posO.y = y;
}

//Accesseur de l'Objet pour récupérer la position de l'objet
Vect2 Objet::getPos()const  {

    return posO;
}

//Accesseur de l'Objet pour récupérer le type de l'Objet
Type Objet::getType()const  {

    return typeO;
}

//Mutateur de l'Objet qui redéfinit le type de l'objet
void Objet:: setType(const Type & t )
{
    typeO=t;
}