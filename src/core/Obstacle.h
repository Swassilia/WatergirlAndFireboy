#ifndef _Obstacle
#define _Obstacle
#include "Type.h"
#include "Vect2.h"

class Obstacle
{

private:

    Type type_ob;

    Vect2 pos;

    int dir;

    unsigned int taillex; //la taille de l'obstacle

    unsigned int tailley;

public:

    Obstacle(Type type_ob, Vect2 pos, unsigned int taille_x, unsigned int taille_y);

    ~Obstacle();

    void bougeAuto();

};


#endif