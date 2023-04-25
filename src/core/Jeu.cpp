#include <cstddef>
#include <iostream>
#include <chrono>
#include <math.h>
#include <thread>
#include "Jeu.h"

using namespace std;

//Constructeurs  
Jeu::Jeu(){
    feu = Personnage(Feu,2,18);
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
const Objet Jeu::getBloc()const{
    return bloc;
}

// gravite dans perso qui est ensuite appelé dans action clavier

/******************************************************************************************/
// detecte quelle touche a été pressé
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
// applique la gravité sur les personnages
void Jeu:: Gravite(bool vr)
{
    eau.Gravite(pla);
    feu.Gravite(pla);
}
// Fait bouger les bloque automatiquement 
void Jeu::ActionAuto(){
    
    pla.bougeAuto();
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
}
//fonction qui calcule si deux elements sont sur la meme case
bool Jeu::collision(const Personnage& per,const Objet & obj){

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y)
        return true;

    return false;
}
// // test
// bool Jeu::collisionPorteE(const Personnage& per,const Objet & obj){

//     if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y&&
//     obj.getType()==PorteE)
//         return true;

//     return false;
// }
// bool Jeu::collisionPorteF(const Personnage& per,const Objet & obj){

//     if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y&&
//     obj.getType()==PorteF)
//         return true;

//     return false;
// }
// revoie vrai si les deux persos sont sur leurs portes respectives et ainsi gagne la partie
// bool Jeu:: succes(const Objet & obj,const Objet & ob){
//     return collisionPorteF(feu,ob)&&collisionPorteE(eau,obj);

// }
//revoie vrai si les personnages touches un éléments qu'il ne devrait pas et donc perdent 
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
//augmente la variable score une fois que les personnages ont touché
//un de leur bonus
void Jeu:: ajouteScore(Plateau pla)
{
    for (int i=0; i<30; i++)
   { if (pla.getObjet(i).getType()==DiamantFeu&&collision(feu, pla.getObjet(i))) 
    {
        score++;
        cout<<score<<endl;
        pla.setPlateau(pla.getObjet(i).getPos(), SPACE);
        cout<<pla.getPlateau(pla.getObjet(i).getPos().x, pla.getObjet(i).getPos().y)<<endl;

    }
    
    if (pla.getObjet(i).getType()==DiamantEau&&collision(eau, pla.getObjet(i) )) 
    {
        score++;
        pla.setPlateau(pla.getObjet(i).getPos(), SPACE);
        cout<<pla.getPlateau(pla.getObjet(i).getPos().x, pla.getObjet(i).getPos().y);
    }
    }

}
void Jeu:: testRegressionJeu(){
    Jeu jeu;
    const Personnage& Fille = jeu.getPersonnageEau();
    const Personnage& Garcon = jeu.getPersonnageFeu();
    const Plateau& terrain = jeu.getPlateau();

    jeu.ActionAuto();   

}