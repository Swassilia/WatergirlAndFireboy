#include "Plateau.h"

Plateau(){
    dimx=0;
    dimy=0;
    tabb= nullptr;
    tabo= nullptr;
    


}
~Plateau(){
    dimx=0;
    dimy=0;

    if(tabb!= nullptr){ 
        delete [] tabb;
        tabb = nullptr;
    }



    //pareil destruction du plateau?

}
int Plateau::getXY(){

}
int Plateau::getDimx(){

}
int Plateau::getDimy(){

}
int Plateau::tempEcoule(){

}
void Plateau::mangeBonus(){

}

/*void Plateau:: placerbonus(){
    for i allant des dimension
    for j allant...
    bonus(i, j)
    while la case n'est pas un # et qu'elle n'est pas déjà occupée

}*/
void Plateau::AjoutBonus(){

    
}