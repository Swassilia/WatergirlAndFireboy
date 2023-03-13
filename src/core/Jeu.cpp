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
// bool Jeu::collision_P_B(const Personnage per, const Bonus bon ){
//     //utiliser mangeBonus
// }
void Jeu::AjoutScore(const Bonus bon,const Personnage per){
    if(collision(eau,(bon.type_bon == DiamondE)) || collision(feu,(bon.type_bon == DiamondF))){
        score ++;
    }
}

//A MODIFIER DAPRES LE TAB D'OBSTACLE
bool Jeu::succe()const{
    for(int i=0; i<pla.dimx;i++){
        for(int j=0; j<pla.dimy; j++){
            if(collision(eau,(tabO[i][j].type_ob == PorteE)) && collision(feu,(tabO[i][j].type_ob == PorteF))){
            return true;
            }
        }
    }   
}
bool Jeu::perte()const{
    for (int i=0; i<pla.dimx;i++){
        for(int j=0; j<pla.dimy; j++){
            if(collision(eau,(tabO[i][j].type_ob == Lava))){
                return true;
        }else
            if(collision(feu,(tabO[i][j].type_ob == Riviere))){
            return true;
        }else
            if(collision(eau,(tabO[i][j].type_ob == O_Vert)) || collision(feu,(tabO[i][j].type_ob == O_Vert))){
            return true;
        }
        }
    }
}
