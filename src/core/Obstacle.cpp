#include "Obstacle.h"
#include <math.h>

Obstacle::Obstacle(Type t,const int x, const int y){ 
    pos.x =x;
    pos.y =y;
    dir=0;
    if (t==Bloc || t==PorteE || t==PorteF){
        type_ob= t;
    }
    int i= (rand ()% 7) + 4 //pas sure du random
    switch (i)
    {
    case 4: 
        type_ob= Lava;
        break;
    case 5:
        type_ob= Riviere;
        break;
    case 6:
        type_ob= O_Vert;
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

}
Vect2 Obstacle::getPos(float posx, float posy){
    pos.x = posx;
    pos.y = posy;
}

void Obstacle::bougeAuto(const Plateau &p){ //pas vraiment compris, precicer que c'est pour les blocs non? #esra 
    int dx [4] = { 1, 0, -1, 0};
    int dy [4] = { 0, 1, 0, -1};
    int xtmp,ytmp;
    xtmp = pos.x + dx[dir];
    ytmp = pos.y + dy[dir];
    pos.x = xtmp;
    pos.y = ytmp;
}
