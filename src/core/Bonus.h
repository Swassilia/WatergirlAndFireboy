#ifndef _Bonus
#define _Bonus
#include "Vect2.h"
#include "Type.h"

class Bonus
{
private:

    Type diamantE;

    Type diamantF;

    Vect2 pos_E;

    Vect2 pos_F;



public:

    Bonus(unsigned int posx, unsigned int posy );

    ~Bonus();

};


#endif