#include "Jeu.h"

//Constructeurs  
Jeu::Jeu(){
    feu = Personnage(Feu, 0,0);
    eau = Personnage(Eau, 0,0);

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

}
 bool Jeu::collision_B(const Personnage & per,const Bonus & bon){
    if (per.getType()==Eau)
    {
        return(distance(per.getPos(), bon.getPos())<0.1 && bon.type_bon==DiamantEau)
    }
    else if 
    {
        if (per.getType==Eau)
        {
            return(distance(per.getPos(), bon.getPos())<0.1 && bon.type_bon==DiamantFeu)
        }
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