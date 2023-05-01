#include <cstddef>
#include <iostream>
#include <chrono>
#include <math.h>
#include <thread>
#include "Jeu.h"

using namespace std;

//Constructeur par défaut du jeu qui initialise un plateau et y place les personnages
//Score initialisé à 0
Jeu::Jeu(){
    feu = Personnage(Feu,2,18);
    eau = Personnage(Eau, 2,17);
    pla = Plateau();
    score = 0;
}

//Accesseur qui récupère la donnée membre pla, le Plateau du jeu
const Plateau Jeu::getPlateau()const{
    return pla;
}

//Accesseur qui Récupère la donnée membre eau, le Personnage de type eau
const Personnage Jeu::getPersonnageEau()const{
    return eau;
}

//Accesseur qui Récupère la donnée membre feu, le Personnage de type feu
const Personnage Jeu::getPersonnageFeu()const{
    return feu;
}

/******************************************************************************************/

//Détecte la touche préssée par le joueur
//q,d,z déplacent le personnage eau
//k,m,o déplacent le personnage feu
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

//décide d'appliquer ou non la gravité sur les déplacements des personnages
void Jeu:: Gravite(bool vr)
{
    eau.Gravite(pla);
    feu.Gravite(pla);
}

//Fait bouger les blocs du jeu automatiquement 
void Jeu::ActionAuto(Plateau &pla){
    
      // Parcours du tableau pour trouver l'objet de type Bloc et le déplacer en dessous si la case est vide
        for(int i = 0; i < 2; i++){
        
            Vect2 pos= pla.getObjet(i).getPos();
            // vitesse  = 1;
           // cout<<x<<" "<<y<<endl;

            //printf("X : %d   Y : %d ", x, y);
            if(pos.y - 1 >= 7 ){
                pla.setPlateau(make_Vect2(pos.x,pos.y-1),BLOC);
                pla.setPlateau(pos,SPACE);
                 pla.getObjet(i).setPos(pos.x, pos.y-1);
                cout<<pos.x<<" "<<pos.y<<endl;
                cout<<endl;
                // assert(x<dimx);
                // assert(y<dimy);
            }else
             pla.setPlateau(make_Vect2(pos.x,pos.y+3),BLOC);
            // setPlateau(make_Vect2(x,y+3),BLOC);
                        pla.setPlateau(pos,SPACE);
        }
        for(int i = 2; i < 4; i++){
        
            Vect2 pos= pla.getObjet(i).getPos();
            // vitesse  = 1;
            cout<<pos.x<<" "<<pos.y<<endl;
            
            //printf("X : %d   Y : %d ", x, y);
            if(pos.y - 1 >= 8 ){
                pla.setPlateau(make_Vect2(pos.x,pos.y-1),BLOC);
                pla.setPlateau(pos,SPACE);
                pla.getObjet(i).setPos(pos.x, pos.y-1);
                //cout<<x<<" "<<y<<endl;
                cout<<endl;
                // assert(pos.x<dimx);
                // assert(pos.y<dimy);
            }else
            pla.setPlateau(make_Vect2(pos.x,pos.y+3),BLOC);
            pla.setPlateau(pos,SPACE);

        }
}

//Fonction qui calcule si deux elements sont sur la meme case
bool Jeu::collision(const Personnage& per,const Objet & obj){

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y)
        return true;

    return false;
}

//Renvoie vrai si les deux persos sont sur leurs portes respectives et ainsi gagne la partie
bool Jeu:: succes(Plateau pla){
    if (collision(feu,pla.getObjet(13))&&collision(eau,pla.getObjet(12)))
     return true  ;
    
    return false;
 }

//Renvoie vrai si les personnages touchent un élément qu'ils ne devraient pas et donc perdent 
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

//augmente la donnée membre score à chaque collision entre un personnage et un bonus
void Jeu:: ajouteScore(Plateau &pla)
    {

        for (int i=0; i<30; i++)
        
        { 
        if (pla.getObjet(i).getType()==DiamantFeu &&collision(feu, pla.getObjet(i))) 
        {
            score++;
            cout<<"le score est "<<score<<" "<<endl;
            pla.setObjet(i,Defaut);
            pla.setPlateau(pla.getObjet(i).getPos(), SPACE);
         }
        if (pla.getObjet(i).getType()==DiamantEau&&collision(eau, pla.getObjet(i) )) 
        {
            score++;
            cout<<"le score est "<<score<<" "<<endl;
            pla.setObjet(i,Defaut);
            pla.setPlateau(pla.getObjet(i).getPos(),SPACE);

         }

        }
    }

//test de régression pour le jeu
void Jeu:: testRegressionJeu(){
    Jeu jeu;
    const Personnage& Fille = jeu.getPersonnageEau();
    const Personnage& Garcon = jeu.getPersonnageFeu();
    const Plateau& terrain = jeu.getPlateau();

    // jeu.ActionAuto(terrain);   

}