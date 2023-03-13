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

public:
    Type type_ob;

    Obstacle(Type t, const int x, const int y);

    ~Obstacle();

    Vect2 getPos(float pox, float posy);
    
    void bougeAuto(const Plateau &p);

};


#endif