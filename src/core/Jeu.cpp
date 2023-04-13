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
    ob = Objet(Bloc,ob.getPos().x, ob.getPos().y);
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
const Objet Jeu::getObjet()const{
    return ob;
}
// gravite dans perso qui est ensuite appelé dans action clavier

/******************************************************************************************/
bool Jeu::ActionClavier(const char touche){  
        eau.Gravite(pla);
        feu.Gravite(pla); 
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
 void Jeu::ActionAuto(const Plateau &pla){
    int dx [4] = { 0, 1, 0, 1};
    int dy [4] = { 0, -1, 0, -1};
    int xtmp,ytmp;
    int x = ob.getPos().x;
    int y = ob.getPos().y;
    xtmp = x - dx[ob.dir];
    ytmp = y - dy[ob.dir];
    // if (pla.EstPosValide(xtmp,ytmp)) {
    //     cout<<"ici"<<endl;
    //     x = +xtmp;
    //     y = +ytmp;
    // }else 
    ob.dir = rand()%4;

 }


bool Jeu::collision(const Personnage& per,const Objet & obj){

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y)
        return true;

    return false;
}

bool Jeu::succes(){
    if(obj.getType()==PorteE){
        if(collision(feu,obj)){ 
            return true;
        }
    return false;
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


void Jeu:: testRegressionJeu(){
    Jeu jeu;
    const Personnage& Fille = jeu.getPersonnageEau();
    const Personnage& Garcon = jeu.getPersonnageFeu();
    
    const Plateau& terrain = jeu.getPlateau();

}