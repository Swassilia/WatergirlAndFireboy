#ifndef _Bonus
#define _Bonus
#include "Vect2.h"
#include "Type.h"

class Bonus
{
//je pense qu'on va devoir faire deux type de bonus, bonusFeu et bonusEau
// si on laisse "type type_b" dans le constructeur ca sera qu'un seul type en mode "eau"
//donc on aura pas de diamant feu
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