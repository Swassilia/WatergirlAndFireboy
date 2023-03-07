#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include "Personnage.h"
using namespace std;



Personnage::Personnage(const Type & t)
{
    type_p= t;
    vivant=true;
    
    
}

Personnage::~Personnage()
{
    vivant=false;
    
}

void Personnage:: deplacer (const Plateau & p, int n )
{
    if(n>2);
}

float Personnage:: getX()
{
    return pos.x; 
}
float Personnage:: getY()
{
    return pos.y;
}

void Personnage:: sauter()
{

}

void Personnage::entrernom()
{

}
