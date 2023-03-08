#include "Obstacle.h"

Obstacle::Obstacle(unsigned int posx, unsigned int posy){ //je ne pense pas que ca se passe comme ca pour la construction
    pos.x =posx;
    pos.y =posy;
    dir=0;
    int i= (rand()%(7-4))+4;
    switch (i)
    {
    case 4: 
        type_ob= Lava;
        taillex= 1;
        tailley=1;
        break;
    case 5:
        type_ob= Riviere;
        taillex= 1;
        tailley=1;
        break;
    case 6:
        type_ob=bloc;
        taillex= 2;
        tailley=2;
        break;
    default:
        break;
    }

}

Obstacle::~Obstacle()
{
    pos.x =0.0;
    pos.y =0.0;
    dir=0;
    type_ob= defaut;
    taillex=0;
    tailley= 0;

}


void Obstacle::bougeAuto(const Plateau &p){
    int dx [4] = { 1, 0, -1, 0};
    int dy [4] = { 0, 1, 0, -1};
    int xtmp,ytmp;
    xtmp = pos.x + dx[dir];
    ytmp = pos.y + dy[dir];
    pos.x = xtmp;
    pos.y = ytmp;
}
