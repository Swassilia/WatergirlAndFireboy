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
    feu.getType()=default;
    eau.getType()=default;
    if(tab!=nullptr){
        delete []tab;
        tab = nullptr;
    }
    score = 0;
    bon = defaut;
}
Plateau Jeu::getPlateau(){
    return pla;
}
Personnage Jeu::getPersonnage(){
    if(personne.getType()=Eau){
        return Eau;
    }else
    if(personne.getType()=Feu){
        return Feu;
    }
}
void Jeu::ActionClavier(){
    if(personne.getType()=Eau){
    switch(touche) {
            case 'q' :
                    pac.gauche(pla);
                    break;
            case 'd' :
                    pac.droite(pla);
                    break;
            case 'z' :
                    pac.haut(pla);
                    break;
            case 's' :
                    pac.bas(pla);
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
                    pac.gauche(pla);
                    break;
            case 'm' :
                    pac.droite(pla);
                    break;
            case 'o' :
                    pac.haut(pla);
                    break;
            case 'l' :
                    pac.bas(pla);
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
    
}
