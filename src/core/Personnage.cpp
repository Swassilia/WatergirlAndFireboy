#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include "Personnage.h"
using namespace std;


Personnage::Personnage(const Type & t, float x, float y)
{

    pos=make_Vect2(x,y);
    dir= make_Vect2(0, -1)
    type_p=t;ll
    vivant=true;
    
}

Personnage::~Personnage()
{
    vivant=false;
    
}

void Personnage:: DeplacerG()
{
    pos.x--;
}
void Personnage:: DeplacerD ()
{
    pos.x++;
    
}
void Personnage::DeplacerH ()
{
    pos.y+=3;
    
}

float Personnage:: getX()
{
    return pos.x; 
}
float Personnage:: getY()
{
    return pos.y;
}
void Personnage::entrernom()
{

}
