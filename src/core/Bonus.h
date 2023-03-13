#ifndef _Bonus
#define _Bonus
#include "Vect2.h"
#include "Type.h"

class Bonus
{
private:



public:

    Vect2 pos;
    Type type_bon;
    Bonus();
    Bonus(Type t, unsigned int posx, unsigned int posy );

    ~Bonus();

};


#endif