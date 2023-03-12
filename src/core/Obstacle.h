#ifndef _Obstacle
#define _Obstacle
#include "Type.h"
#include "Vect2.h"
#include "Plateau.h"

class Obstacle
{

private:

    

    Vect2 pos;

    int dir;

    unsigned int taillex; //la taille de l'obstacle

    unsigned int tailley;

public:
    Type type_ob;
    Obstacle(Type type_ob, Vect2 pos);

    ~Obstacle();
    Vect2 getPos(float pox, float posy);
    void bougeAuto(const Plateau &p);

};


#endif