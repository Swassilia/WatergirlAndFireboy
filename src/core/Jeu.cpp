#include <cassert>
#include <cstddef>
#include <iostream>
#include "Jeu.h"

using namespace std;

//Constructeurs  
Jeu::Jeu(){
    feu = Personnage(Feu, 29,13);
    eau = Personnage(Eau, 3,13);

    pla = Plateau();
    score = 0;
}

const Plateau Jeu::getPlateau()const{
    return pla;
}
const Personnage Jeu::getPersonnageEau()const{
    return eau;
}
const Personnage Jeu::getPersonnageFeu()const{
    return feu;
}


/******************************************************************************************/
void Jeu::ActionClavier(const char touche){    
    switch(touche) {
            case 'q' :
                    eau.DeplacerG();
                    break;
            case 'd' :
                    eau.DeplacerD();
                    break;
            case 'z' :
                    eau.DeplacerH();
                    break;
            case 'k' :
                    feu.DeplacerG();
                    break;
            case 'm' :
                    feu.DeplacerD();
                    break;
            case 'o' :
                    feu.DeplacerH();
                    break;
        }
        

}
void Jeu::ActionAuto(){
    //ob_Bloc.bougeAuto(pla);//a faire avec esra
}

bool Jeu::collision_O(const Personnage& per,const Obstacle& ob){
    if(distance(per.getPos(), ob.getPos())<0.1 && (per.getType()==Feu)&&// test si le personnage est de type feu
    (ob.getType()==PorteF ||ob.getType()==O_Vert|| ob.getType()==Riviere )){
        return true;
    }else
    if(distance(per.getPos(), ob.getPos())<0.1 && (per.getType()==Eau)&&// test si le personnage est de type eau 
    (ob.getType()==PorteE ||ob.getType()==O_Vert|| ob.getType()==Lava ))
    {
        return true;
    }
    return false;
}
 bool Jeu::collision_B(const Personnage & per,const Bonus & bon){
    assert(per.getType()==Eau || per.getType()==Feu);
    if (per.getType()==Eau)
    {
        return(distance(per.getPos(), bon.getPos())<0.1 && bon.type_bon==DiamantEau);
    }
    if (per.getType()==Feu)
    {
        return(distance(per.getPos(), bon.getPos())<0.1 && bon.type_bon==DiamantFeu);
    }
    return false;
}


bool Jeu::succe(const Personnage& per, const Obstacle& ob){
    if(per.getType()==Eau && ob.getType()==PorteE){
        if(collision_O(per,ob)){ 
            return true;
        }
    }else 
    if(per.getType()== Feu && ob.getType()==PorteF){
        if(collision_O(per,ob)){
            return true;
        }
    }
    return false;
}
bool Jeu::perte(const Personnage&per , const Obstacle& ob){
    if(per.getType()==Eau && ob.getType()== Lava){
        if(collision_O(per,ob))return true;
    }else
    if(per.getType()== Eau && ob.getType()== O_Vert){
        if(collision_O(per,ob))return true;
    }else
    if(per.getType()== Feu && ob.getType() == Riviere){
        if(collision_O(per,ob))return true;
    }else
    if(per.getType()== Feu && ob.getType()== O_Vert){
        if(collision_O(per,ob))return true;
    }
    return false;
}

void Jeu::testRegression_Jeu(){
    Jeu jeu;
    const Personnage& Fille = jeu.getPersonnageEau();
    const Personnage& Garcon = jeu.getPersonnageFeu();
    
    const Plateau& terrain = jeu.getPlateau();
    const Bonus& bon = Bonus();
    const Obstacle& porte = Obstacle();
    const Obstacle& riviere = Obstacle();

    jeu.ActionClavier('c');
    jeu.collision_B(Fille, bon);
    jeu.collision_O(Fille,porte);
    jeu.collision_O(Garcon,riviere);

}