#ifndef _Plateau
#define _Plateau
#include "Bonus.h"
#include "Obstacle.h"

class Plateau
{
private:


    unsigned int dimx, dimy;

    Obstacle * tabO; // tableau qui contient les obstacles du plateau
    
    Bonus * tabB; 

public:

    Plateau();

    ~Plateau();

    int getXY();
    void setDimx(int x);
    int getDimx()const;
    void setDimy(int y);
    int getDimy()const;
    
    void PlacerBonus();
    void EstPosValide(const int x, const int y);
    void mangeBonus(const int x, const int y);  //il faudra modifier ces fonctions si on impose 2 bonus (un pour le feu et l'autre pour l'eau)
    void AjoutBonus(Bonus bon);    
    int tempEcoule();

};
#endif
