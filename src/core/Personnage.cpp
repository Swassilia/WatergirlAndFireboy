#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Personnage.h"
using namespace std;

Personnage::Personnage(){
    pos = make_Vect2(0,0);
    nom = nullptr;
    vivant = true;
}
Personnage::Personnage(const Type & t, int x, int y)
{
    assert (x>=0&&y>=0);
    assert(t==Feu || t==Eau);
    pos=make_Vect2(x,y);
    type_p=t;
    nom=nullptr;      
    vivant=true;
}
Personnage::~Personnage()
{
    vivant=false;
    type_p=Defaut;
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
void Personnage:: DeplacerG( const  Plateau &pla)
{
    // assert(pos.x>0);
    if (pla.EstPosValide(pos.x-1 ,pos.y)) pos.x--;
}
void Personnage:: DeplacerD ( const Plateau &pla)
{
    // assert(pos.x>0);
    if (pla.EstPosValide(pos.x+1,pos.y)) pos.x++;
    
}
void Personnage::DeplacerH (const  Plateau &pla)
{
    if (pla.EstPosValide(pos.x,pos.y-1 )) pos.y-=2;
}

void  Personnage::Gravite(const  Plateau &pla)
{
    if (pla.EstPosValide(pos.x,pos.y+1))
    {
        sleep(0.1);
         pos.y+=1; // la coordonné (0,0) est en haut a gauche y doit donc augmenter pour descendre
    }
   
}

