#ifndef _Bonus
#define _Bonus
#include "Vect2.h"
#include "Type.h"

class Bonus
{
private:

    Vect2 pos;


public:

    Type type_bon;

    Bonus(Type t, unsigned int posx, unsigned int posy );

    ~Bonus();

};


#endif