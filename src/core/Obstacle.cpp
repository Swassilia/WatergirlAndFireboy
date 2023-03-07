#include "Obstacle.h"

Obstacle(Type type_ob, Vect2 pos){
    pos.x =1.0;
    pos.y =1.0;
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
