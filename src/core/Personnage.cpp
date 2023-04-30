#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Personnage.h"
using namespace std;

//constructeur par défaut du personnage
Personnage::Personnage(){

    type_p=Defaut;
    pos = make_Vect2(0,0);
    nom = nullptr;
}

//constructeur par copie du personnage pour lui attribuer un type et une position (passés en paramètre)
//assert pour vérifier que les coordonnées voulues sont bien dans les dimensions du plateau et que le type est soit eau soit feu
Personnage::Personnage(const Type & t, int x, int y)
{
    assert (x>=0&&y>=0);
    assert(t==Feu || t==Eau);
    pos=make_Vect2(x,y);
    type_p=t;
    nom=nullptr;      
}

//destructeur du personnage
Personnage::~Personnage()
{
    type_p=Defaut;
    pos=make_Vect2(0,0);
    nom= nullptr;   
}

//Accesseur qui récupére la position du personnage
Vect2 Personnage::getPos()const{
    return pos;
}

//Mutateur qui modifie la position du personnage
void Personnage::setPos(const unsigned int x, const unsigned int y){
    pos.x = x;
    pos.y = y;
}

//attribuer un nom au personnage
void Personnage::entrernom()
{
    cout<<"Entrez votre nom"<<endl;
    cin>>nom;
    cout<<endl;
}

//Accesseur qui récupére le type du personnage
Type Personnage::getType()const {
    return type_p;
}

//déplacer le personnage à gauche en diminuant la coordonnée en x
//tout en vérifiant si la case d'après est une position valide
void Personnage:: DeplacerG( const  Plateau &pla)
{
    // assert(pos.x>0);
    if (pla.EstPosValide(pos.x-1 ,pos.y)) pos.x--;
}

//déplacer le personnage à droite en augmentant la coordonnée en x
//tout en vérifiant si la case d'après est une position valide
void Personnage:: DeplacerD ( const Plateau &pla)
{
    // assert(pos.x>0);
    if (pla.EstPosValide(pos.x+1,pos.y)) pos.x++;
    
}

//déplacer le personnage vers le haut en diminuant la coordonnée en y
//tout en vérifiant si la case du haut est une position valide
void Personnage::DeplacerH (const  Plateau &pla)
{
    if (pla.EstPosValide(pos.x,pos.y-1)) pos.y-=2;
    // const int hauteurMax = 2;
    // const int tempsSaut = 6;
    // static int tempsEcoule = 0;
    // static bool enSaut = false;
    // if (enSaut)
    // {
    //     if (tempsEcoule < tempsSaut)
    //     {
    //         pos.y -= hauteurMax;
    //         tempsEcoule++;
    //     }
    //     else if (tempsEcoule < tempsSaut * 2)
    //     {
    //         pos.y += hauteurMax;
    //         tempsEcoule++;
    //     }
    //     else
    //     {
    //         enSaut = false;
    //         tempsEcoule = 0;
    //     }
    // }
    // else
    // {
    //     if (pla.EstPosValide(pos.x, pos.y - 1))
    //     {
    //         enSaut = true;
    //     }
    // }
}

//pour appliquer une gravité au personnage, on augmente la coordonnée en y pour simuler une chute
////tout en vérifiant si la case du bas est une position valide
void  Personnage::Gravite(const  Plateau &pla)
{
    if(pla.EstPosValide(pos.x,pos.y+1))
    {
        // sleep();
         pos.y+=1; // la coordonné (0,0) est en haut a gauche y doit donc augmenter pour descendre
    }
   
}

