#include <cassert>
#include <cstddef>
#include <iostream>
#include <chrono>
#include <math.h>
#include "Jeu.h"

using namespace std;

//Constructeurs  
Jeu::Jeu(){
    feu = Personnage(Feu,2,18);
    eau = Personnage(Eau, 2,17);
    pla = Plateau();
    score = 0;
    bloc = Objet(Bloc,1, 1);
    diam = Objet(DiamantEau,1,1);
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
const Objet Jeu::getBloc()const{
    return bloc;
}
const Objet Jeu::getDiam()const{
    return diam;
}
// gravite dans perso qui est ensuite appelé dans action clavier

/******************************************************************************************/
bool Jeu::ActionClavier(const char touche){  

        switch(touche) {

            case 'q' :
                eau.DeplacerG(pla);
                break;
            case 'd' :
                eau.DeplacerD(pla);
                break;
            case 'z' :
                eau.DeplacerH(pla);
                break;
            case 'k' :
                feu.DeplacerG(pla);
                break;
            case 'm' :
                feu.DeplacerD(pla);
                break;
             case 'o' :
                feu.DeplacerH(pla);
                break;
        }  
    
    return false;
}
void Jeu:: Gravite(bool vr)
{
    eau.Gravite(pla);
    feu.Gravite(pla);
}
 void Jeu::ActionAuto(){
    pla.boueAuto(bloc);
 }


bool Jeu::collision(const Personnage& per,const Objet & obj){

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y)
        return true;

    return false;
}
bool Jeu::collisionPorteE(const Personnage& per,const Objet & obj){

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y&&
    obj.getType()==PorteE)
        return true;

    return false;
}
bool Jeu::collisionPorteF(const Personnage& per,const Objet & obj){

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y&&
    obj.getType()==PorteF)
        return true;

    return false;
}

bool Jeu:: succes(const Objet & obj,const Objet & ob){
    return collisionPorteF(feu,ob)&&collisionPorteE(eau,obj);

}

bool Jeu::perte(const Objet & obj){
    if(obj.getType()== Lava){
        return collision(eau,obj);
    }else
    if(obj.getType()==O_Vert){
        return (collision(feu,obj)||collision(eau,obj));
    }else
    if(obj.getType() == Riviere){
        return(collision(feu,obj));
    }else
    return false;
}
void Jeu:: ajouteScore(Plateau & pla)
{
    if (collision(feu, diam)) 
    {
        score++;
        pla.setPlateau(diam.getPos(), SPACE);
    }
    
    if (collision(eau, diam )) score++;

}

void Jeu:: testRegressionJeu(){
    Jeu jeu;
    const Personnage& Fille = jeu.getPersonnageEau();
    const Personnage& Garcon = jeu.getPersonnageFeu();
    const Plateau& terrain = jeu.getPlateau();

}