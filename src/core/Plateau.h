#ifndef _Plateau
#define _Plateau
#include "Bonus.h"
#include "Obstacle.h"

class Plateau
{
private:

    enum CasePlateau { WALL='#', BLOC='_', SPACE=' ', BONUS='.', OBS='o', PORTE='p'};

    Obstacle * tabO; // tableau qui contient les obstacles du plateau
    
    Bonus * tabB; 

    CasePlateau plateau[50][50];

public:

    unsigned int dimx, dimy;

    Plateau();

    ~Plateau();

    int getXY(const int x, const int y);

    void setDimx(int x);

    int getDimx()const;

    void setDimy(int y);

    int getDimy()const;
    
    void PlacerBonus();

    void PlacerObstacle();

    bool EstPosValide(const int x, const int y)const;

    void mangeBonus(const int x, const int y);  


};
#endif
