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

//Récupère la donnée membre pla qui est le Plateau du jeu
const Plateau Jeu::getPlateau()const{
    return pla;
}

//Récupère la donnée membre eau qui est le Personnage de type eau
const Personnage Jeu::getPersonnageEau()const{
    return eau;
}

//Récupère la donnée membre feu qui est le Personnage de type feu
const Personnage Jeu::getPersonnageFeu()const{
    return feu;
}

// //Récupère la donnée membre Plateau
// const Objet Jeu::getBloc()const{
//     return bloc;
// }

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

//Applique la gravité sur les personnages
void Jeu:: Gravite(bool vr)
{
    eau.Gravite(pla);
    feu.Gravite(pla);
}

//Fait bouger les blocs automatiquement 
void Jeu::ActionAuto(){
    
    pla.bougeAuto();
}

//Fonction qui calcule si deux elements sont sur la meme case
bool Jeu::collision(const Personnage& per,const Objet & obj){

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y)
        return true;

    return false;
}

//Renvoie vrai si les deux persos sont sur leurs portes respectives et ainsi gagne la partie
bool Jeu:: succes(const Objet & obj,const Objet & ob){
     return collision(feu,ob)&&collision(eau,obj);
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

//augmente la variable score une fois que les personnages ont touché un de leur bonus
//idée ESRA 
    // void Jeu:: ajouteScore()
    // {

    //         score++;
    //         cout<<score<<endl;

    //      }

void Jeu:: ajouteScore(Plateau &pla)
    {

        for (int i=0; i<30; i++)
        { 
        if (pla.getObjet(i).getType()==DiamantFeu &&collision(feu, pla.getObjet(i))) 
        {
            score++;
            cout<<score<<endl;
            // int x = pla.getObjet(i).getPos().x;
            // int y = pla.getObjet(i).getPos().y;
            pla.setObjet(i,Defaut);
            pla.setPlateau(pla.getObjet(i).getPos(), SPACE);
            cout<<pla.getObjet(i).getType()<<" "<<Defaut;
         }
        if (pla.getObjet(i).getType()==DiamantEau&&collision(eau, pla.getObjet(i) )) 
        {
            score++;
            cout<<"le score est "<<score<<" "<<endl;
            int x = pla.getObjet(i).getPos().x;
            int y = pla.getObjet(i).getPos().y;
            pla.setObjet(i,Defaut);
            pla.setPlateau(pla.getObjet(i).getPos(),SPACE);
            cout<<x<<" "<<y<<endl;
            cout<<" le type de  est "<<pla.getObjet(i).getType()<<" "<<i<<" le type de space est "<<Defaut<<endl;
            cout<<" le type de  est "<<pla.getPlateau(x,y)<<" "<< i <<" le type de space est "<<SPACE<<endl;
            //cout<<pla.getPlateau(pla.getObjet(i).getPos().x, pla.getObjet(i).getPos().y);
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