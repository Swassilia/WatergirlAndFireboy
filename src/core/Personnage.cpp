#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include "Personnage.h"
using namespace std;

Personnage::Personnage(){
    pos = make_Vect2(0,0);
    dir = make_Vect2(0, -1);
    nom = nullptr;
    vivant = true;
}
Personnage::Personnage(const Type & t, int x, int y)
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
    type_p=Defaut;
    dir=make_Vect2(0,0);
    pos=make_Vect2(0,0);
    nom= nullptr;
    
}
Vect2 Personnage::getPos()const{
    return pos;
}
void Personnage::entrernom()
{
    cout<<"Entrez votre nom"<<endl;
    cin>>nom;
    cout<<endl;

}
Type Personnage::getType()const {
    return type_p;
}
void Personnage:: DeplacerG()
{
    assert(pos.x>0);
    pos.x--;
}
void Personnage:: DeplacerD ()
{
    assert(pos.x>0);
    pos.x++;
    
}
void Personnage::DeplacerH ()
{
    assert(pos.y>0);
    pos.y+=3;
    
}


