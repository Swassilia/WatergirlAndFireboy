#ifndef _Plateau
#define _Plateau
#include "Bonus.h"
#include "Obstacle.h"

class Plateau
{
private:

    enum CasePlateau { WALL='#', BLOC='_', SPACE=' ', BONUS='.', OBS='o', PORTEEAU='E', PORTEFEU= 'F'};

    Obstacle * tabO; 
    
    Bonus * tabB; 

    CasePlateau plateau[50][50];

public:

    int dimx, dimy;

    Plateau();

    ~Plateau();

    int getXY(const int x, const int y);

    int getDimx()const;

    int getDimy()const;

    CasePlateau getPlateau (const int x, const int y);

    Obstacle getObstacle (const int x, const int y);

    bool EstPosValide(const int x, const int y);

    void mangeBonus(const int x, const int y);  


};
#endif
