#ifndef _Obstacle
#define _Obstacle
#include "Type.h"
#include "Vect2.h"

class Obstacle
{
private:
/* si on met rivière ici comme obstacle :
    Type rivière; et le constructeur défini si c'est de l'eau du feu ou le truc vert qui tue les 2
    */
    Type type_ob;
    Vect2 pos;
    int dir;
public:
    Obstacle(Type type_ob, Vect2 pos);
    ~Obstacle();
    void bougeAuto();
};

