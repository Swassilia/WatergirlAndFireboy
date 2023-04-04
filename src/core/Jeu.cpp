#include <cassert>
#include <cstddef>
#include <iostream>
#include <chrono>
#include <math.h>
#include "Jeu.h"

using namespace std;

//Constructeurs  
Jeu::Jeu(){
    feu = Personnage(Feu, 2,15);
    eau = Personnage(Eau, 2,17);
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
// void Jeu::ActionAuto(){
//     //  int temps=elapseTime();
//     int m=(2*cos(400));

// }

bool Jeu::collision(const Personnage& per,const Objet & obj){
    assert(per.getType()==Eau || per.getType()==Feu);

    if(distance(per.getPos(), obj.getPos())<0.1 && (per.getType()==Feu)&&// test si le personnage est de type feu
    (obj.getType()==PorteF ||obj.getType()==O_Vert|| obj.getType()==Riviere ))
    {
        return true;
    }else
    if(distance(per.getPos(), obj.getPos())<0.1 && (per.getType()==Eau)&&// test si le personnage est de type eau 
    (obj.getType()==PorteE ||obj.getType()==O_Vert|| obj.getType()==Lava ))
    {
        return true;
    }
    else
    if (per.getType()==Eau)
    {
        score++;
        return(distance(per.getPos(), obj.getPos())<0.1 && obj.getType()==DiamantEau);
    }
    else
    if (per.getType()==Feu)
    {
        score++;
        return(distance(per.getPos(), obj.getPos())<0.1 && obj.getType()==DiamantFeu);
        
    }
    return false;
}


bool Jeu::succes(const Personnage& per, const Objet& obj){
    if(per.getType()==Eau && obj.getType()==PorteE){
        if(collision(per,obj)){ 
            return true;
        }
    }else 
    if(per.getType()== Feu && obj.getType()==PorteF){
        if(collision(per,obj)){
            return true;
        }
    }
    return false;
}
bool Jeu::perte(const Personnage&per , const Objet& obj){
    if(per.getType()==Eau && obj.getType()== Lava){
        if(collision(per,obj))return true;
    }else
    if(per.getType()== Eau && obj.getType()== O_Vert){
        if(collision(per,obj))return true;
    }else
    if(per.getType()== Feu && obj.getType() == Riviere){
        if(collision(per,obj))return true;
    }else
    if(per.getType()== Feu && obj.getType()== O_Vert){
        if(collision(per,obj))return true;
    }
    return false;
}

void Jeu::testRegression_Jeu(){
    Jeu jeu;
    const Personnage& Fille = jeu.getPersonnageEau();
    const Personnage& Garcon = jeu.getPersonnageFeu();
    
    const Plateau& terrain = jeu.getPlateau();

}