#include "Jeu.h"
//construit 
Jeu::Jeu(){
    feu (Feu, 0,0);
    eau (Eau, 0,0);
    tab = nullptr;
    score = 0;
}
Jeu::~Jeu(){
    feu (Defaut, 0,0);
    eau (Defaut, 0,0);
    if(tab!=nullptr){
        delete []tab;
        tab = nullptr;
    }
    score = 0;
    bon = Defaut;
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

bool Jeu::ActionClavier(){
    int touche;
    
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
    while(true){
        
    }
}

bool Jeu::collision(const Personnage per, bool t){
    //utiliser la distance Vect2
}
bool Jeu::collision_P_B(const Personnage per, const Bonus bon ){
    //utiliser mangeBonus
}
void Jeu::AjoutScore(const Bonus bon,const Personnage per){
    if(collision_P_B(eau,bon) || collision_P_B(feu,bon)){
        score ++;
    }
}

//A MODIFIER DAPRES LE TAB D'OBSTACLE
bool Jeu::succe()const{
    if(collision(eau,(ob.type_ob == Eau)) && collision(feu,(ob.type_ob == Feu))){
        return true;
    }
}
bool Jeu::perte()const{
    if(collision(eau,(ob.type_ob=Lava)) = true){
        return true;
    }else
    if(collision(feu,(ob.type_ob=Riviere)) = true){
        return true;
    }else
    if(collision(eau,(ob.type_ob=O_Vert)) || collision(feu,(ob.type_ob = O_Vert))){
        return true;
    }
}