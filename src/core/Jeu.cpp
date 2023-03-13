#include "Jeu.h"

//Constructeurs  
Jeu::Jeu(){
    feu = Personnage(Feu, 0,0);
    eau = Personnage(Eau, 0,0);

    pla = Plateau();
    
    ob_Lava = Obstacle(Lava,0,0);
    ob_Riviere = Obstacle(Riviere,0,0);
    ob_O_vert = Obstacle(O_Vert ,0,0);

    ob_PorteE = Obstacle(PorteE,0,0);
    ob_PorteF = Obstacle(PorteF,0,0);

    ob_Bloc = Obstacle(Bloc,0,0);
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

const Obstacle Jeu::getObstacle_Lava()const{
    return ob_Lava;
}
const Obstacle Jeu::getObstacle_Riviere()const{
    return ob_Riviere;
}
const Obstacle Jeu::getObstacle_O_vert()const{
    return ob_O_vert;
}

const Obstacle Jeu::getObstacle_PE()const{
    return ob_PorteE;
}
const Obstacle Jeu::getObstacle_PF()const{
    return ob_PorteF;
}

const Obstacle Jeu::getObstacle_Bloc()const{
    return ob_Bloc;
}
/******************************************************************************************/
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
    ob_Bloc.bougeAuto(pla);
}

bool Jeu::collision_O(const Personnage per, const Obstacle ob){
    float posx, posy;
    if(distance((feu.getPos(feu.getX(),feu.getY())),(ob_Riviere.getPos(posx,posy)))){
        return true;
    }else
    if(distance((feu.getPos(feu.getX(),feu.getY())),(ob_PorteF.getPos(posx,posy)))){ 
        return true;
    }else
    if(distance((feu.getPos(feu.getX(),feu.getY())),(ob_O_vert.getPos(posx,posy)))){
        return true;
    }else
    if(distance((eau.getPos(feu.getX(),feu.getY())),(ob_Lava.getPos(posx,posy)))){
        return true;
    }else
    if(distance((eau.getPos(feu.getX(),feu.getY())),(ob_PorteE.getPos(posx,posy)))){
        return true;
    }else
    if(distance((eau.getPos(feu.getX(),feu.getY())),(ob_O_vert.getPos(posx,posy)))){
        return true;
    }

}
 bool Jeu::collision_B(const Personnage per,const Bonus bon){
     if(distance(eau.getPos(eau.getX(),eau.getY()), bon.pos)){
        return true;
     }else
     if(distance(feu.getPos(feu.getX(),eau.getY()), bon.pos)){
        return true;
     }
}

//A DEMANDER LE PROF :((((
bool Jeu::succe()const{
    for(int i=0; i<pla.dimx;i++){
        for(int j=0; j<pla.dimy; j++){
            if(collision_O(eau,ob_PorteE) && collision_O(feu,ob_PorteF)){
            return true;
            }
        }
    }   
}
bool Jeu::perte()const{
    for (int i=0; i<pla.dimx;i++){
        for(int j=0; j<pla.dimy; j++){
            if(collision_O(eau,ob_Lava)){
                return true;
        }else
            if(collision_O(feu,ob_Riviere)){
            return true;
        }else
            if(collision_O(eau,ob_O_vert) || collision_O(feu,ob_O_vert)){
            return true;
        }
        }
    }
}