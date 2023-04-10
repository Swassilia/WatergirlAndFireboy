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

// gravite dans perso qui est ensuite appelé dans action clavier

/******************************************************************************************/
void Jeu::ActionClavier(const char touche){  
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
    
        

}
 void Jeu::ActionAuto(const Plateau &pla){
    int dx [4] = { 0, 1, 0, 1};
    int dy [4] = { 0, -1, 0, -1};
    int xtmp,ytmp;
    int x = ob.getPos().x;
    int y = ob.getPos().y;
    xtmp = x - dx[ob.dir];
    ytmp = y - dy[ob.dir];
    if (pla.EstPosValide(xtmp,ytmp)) {
        cout<<"ici"<<endl;
        x = +xtmp;
        y = +ytmp;
    }else ob.dir = rand()%4;

 }


bool Jeu::collisionRivE(const Personnage& per,const Objet & obj){
    assert(per.getType()==Eau || obj.getType()==O_Vert||obj.getType()==Lava);

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y &&// test si le personnage est de type feu
    (obj.getType()==O_Vert|| obj.getType()==Lava ))

        return true;

    return false;
}
bool Jeu::collisionRivF(const Personnage& per,const Objet & obj){
    assert(per.getType()==Feu|| obj.getType()==O_Vert||obj.getType()==Riviere);

    if(per.getPos().x==obj.getPos().x &&per.getPos().y==obj.getPos().y &&// test si le personnage est de type feu
    (obj.getType()==O_Vert|| obj.getType()==Riviere ))

        return true;

    return false;
}
//     }else
//     if(distance(per.getPos(), obj.getPos())==0 && (per.getType()==Eau)&&// test si le personnage est de type eau 
//     (obj.getType()==PorteE ||obj.getType()==O_Vert|| obj.getType()==Lava ))//x1==x2
//     {
//         return true;
//     }
//     else
//     if (per.getType()==Eau)
//     {
//         score++;
//         return(distance(per.getPos(), obj.getPos())==0 && obj.getType()==DiamantEau);
//     }
//     else
//     if (per.getType()==Feu)
//     {
//         score++;
//         return(distance(per.getPos(), obj.getPos())==0 && obj.getType()==DiamantFeu);
        
//     }
//     return false;
// }


// bool Jeu::succes(const Personnage& per, const Objet& obj){
//     if(per.getType()==Eau && obj.getType()==PorteE){
//         if(collision(per,obj)){ 
//             return true;
//         }
//     }else 
//     if(per.getType()== Feu && obj.getType()==PorteF){
//         if(collision(per,obj)){
//             return true;
//         }
//     }
//     return false;
// }
bool Jeu::perte(const Personnage&per , const Objet& obj){
    if(per.getType()==Eau && obj.getType()== Lava){
        return collisionRivE(per,obj);
    }else
    if(per.getType()== Eau && obj.getType()== O_Vert){
        return (collisionRivE(per,obj));
    }else
    if(per.getType()== Feu && obj.getType() == Riviere){
        return(collisionRivF(per,obj));
    }//else
    // if(per.getType()== Feu && obj.getType()== O_Vert){
    //     if(collision(per,obj))return true;
    // }
    return false;
}


void Jeu:: testRegressionJeu(){
    Jeu jeu;
    const Personnage& Fille = jeu.getPersonnageEau();
    const Personnage& Garcon = jeu.getPersonnageFeu();
    
    const Plateau& terrain = jeu.getPlateau();

}