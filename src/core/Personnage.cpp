#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include "Personnage.h"
using namespace std;


Personnage::Personnage(const Type & t, float x, float y)
{
    assert (x>=0&&y>=0);
    assert(t==Feu || t==Eau);
    pos=make_Vect2(x,y);
    dir= make_Vect2(0, -1);
    type_p=t;
    nom=nullptr;      
    vivant=true;
}

Personnage::~Personnage()
{
    vivant=false;
    type_p=defaut;
    dir=make_Vect2(0,0);
    pos=make_Vect2(0,0);
    nom= nullptr;
    
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
    cout<<"Entrez votre nom"<<endl;
    cin>>nom;
    cout<<endl;

}
Type Personnage::getType(){
    return type_p;
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


