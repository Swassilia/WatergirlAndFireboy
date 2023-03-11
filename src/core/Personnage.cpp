#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include "Personnage.h"
using namespace std;


Personnage::Personnage(const Type & t, float x, float y)
{

    pos=make_Vect2(x,y);
    dir= make_Vect2(0, -1);
    switch(i)
    {
    case 0:
        type_p = Feu;
        break;
    case 1:
        type_p = Eau;
        break;
    default:
        break;
    }      
    vivant=true;
    //initialisation de prenom et nom?
}

Personnage::~Personnage()
{
    vivant=false;
    /*
    type_p=defaut;
    dir=make_Vect2(0,0);
    pos=make_Vect2(0,0);
    //prenom et nom?
    */
    
}

void Personnage:: DeplacerG()
{
    pos.x--;
}
void Personnage:: DeplacerD ()
{
    pos.x++;
    
}
void Personnage::DeplacerH ()
{
    pos.y+=3;
    
}

float Personnage:: getX()
{
    return pos.x; 
}
float Personnage:: getY()
{
    return pos.y;
}
void Personnage::entrernom()
{
    
}
Type Personnage::getType(){
    return type_p;
}

void Personnage::entrernom()
{
    cout<<"Entrez votre nom"<<endl;
    cin>>nom;
    cout<<endl;

}

