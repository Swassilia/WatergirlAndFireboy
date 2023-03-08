#ifndef _Plateau
#define _Plateau
#include "Bonus.h"
#include "Obstacle.h"

class Plateau
{
private:


    unsigned int dimx, dimy;

    Plateau * tab; //???

    Obstacle * tabo; // tableau qui contient les obstacles du plateau
    
    Bonus * tabb; 

public:

    Plateau(/* args */);

    ~Plateau();

    int getXY();

    int getDimx();

    int getDimy();

    void mangeBonus(Bonus bon);  //il faudra modifier ces fonctions si on impose 2 bonus (un pour le feu et l'autre pour l'eau)
    void AjoutBonus(Bonus bon);
    
    int tempEcoule();

};

