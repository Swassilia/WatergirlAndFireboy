#include "Jeu.h"

Jeu::Jeu(){
    if(personne.getType()=Eau){
        personne = Eau;
    }else
    if(personne.getType()=Feu){
        personne = Feu;
    }
    tab = nullptr;
    score = 0;
}
Jeu::~Jeu(){
    personne.getType()=defaut;
    if(tab!=nullptr){
        delete []tab;
        tab = nullptr;
    }
    score = 0;
    bon = defaut;
}

const Plateau Jeu::getPlateau()const{
    return pla;
}
const Personnage Jeu::getPersonnage()const{
    if(personne.getType()=Eau){
        return Eau;
    }else
    if(personne.getType()=Feu){
        return Feu;
    }
}
bool Jeu::ActionClavier(){
    int touche;
    if(personne.getType()=Eau){
    switch(touche) {
            case 'q' :
                    personne.DeplacerG();
                    break;
            case 'd' :
                    personne.DeplacerD();
                    break;
            case 'z' :
                    personne.DeplacerH();
                    break;
        }
        if (pla.getXY(personne.getX(),personne.getY())=='.') {
            pla.mangeBonus(personne.getX(),personne.getY());
            return true;
        }
        return false;
    }else
    if(personne.getType()=Feu){
        switch(touche) {
            case 'k' :
                    personne.DeplacerG();
                    break;
            case 'm' :
                    personne.DeplacerD();
                    break;
            case 'o' :
                    personne.DeplacerH();
                    break;
        }
        if (pla.getXY(personne.getX(),personne.getY())=='.') {
            pla.mangeBonus(personne.getX(),personne.getY());
            return true;
        }
        return false;
    }

}
void Jeu::ActionAuto(){
    bon.bougeAuto(pla);
}

bool Jeu::succe(){

}
bool Jeu::perte(){

}

int Jeu::calculColl(Vect2 a, Vect2 b){
    
}

bool Jeu::collision(const Personnage per,const Obstacle ob,const Bonus bon,const Plateau & pla){

}

void Jeu::AjoutScore(const Bonus bon,const Personnage per){

}