#ifndef _Plateau
#define _Plateau
#include "Bonus.h"

class Plateau
{
private:
    unsigned int dimx, dimy;
    Plateau *tab;
    Bonus *tab;
public:
    Plateau(/* args */);
    ~Plateau();
    int getXY();
    int getDimx();
    int getDimy();
    void mangeBonus(Bonus bon);
    void AjoutBonus(Bonus bon);
    int tempEcoule();

};

