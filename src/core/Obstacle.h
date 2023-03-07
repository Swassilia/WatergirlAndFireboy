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
public:
    Obstacle(Type type_ob, Vect2 pos);
    ~Obstacle();
    void bougeAuto();
};

