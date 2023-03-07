#ifndef _Bonus
#define _Bonus
#include "Vect2.h"
#include "Type.h"

class Bonus
{
private:
    Type type_b;
    /* 
    si on grade l'idée du .cpp on aura :
    Type diamantF;
    Type diamantE;
    */
    Vect2 pos_b;
public:
    Bonus();
    ~Bonus();
    
};
