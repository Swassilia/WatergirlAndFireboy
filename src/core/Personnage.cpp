#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include "Personnage.h"



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
    if()
}

float Personnage:: getx()
{
    return pos.x; 
}
float Personnage:: gety()
{
    return pos.y;
}

void Personnage:: sauter()
{

}

void Personnage entrernom()
{

}
