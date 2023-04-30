#include <math.h>
#include <iostream>
#include "Vect2.h"

using namespace std;

//constructeur par copie de vecteur
Vect2 make_Vect2 (int x, int y )
 {
     Vect2 v;
     v.x = x;
     v.y = y ;
     return v;
 }

//calcule la distance entre deux vecteurs
int distance( const Vect2 & a,const Vect2 & b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

//Surcharge de l'Operateur + entre deux vecteurs
Vect2 operator+(const Vect2 & a, const Vect2 &b)
{
    return(make_Vect2(a.x+b.x,a.y+b.y));
}

//Surcharge de l'Operateur - entre deux vecteurs
Vect2 operator-(const Vect2& a, const Vect2& b)
{
   return(make_Vect2(a.x-b.x,a.y-b.y));
}

//Surcharge de l'Operateur produit d'un vecteur et d'un entier
Vect2 operator*(int lambda, const Vect2& a)
{
    return (make_Vect2(a.x*lambda, a.y*lambda));
}

//Surcharge de l'Operateur produit d'un entier et d'un vecteur
Vect2 operator*( const Vect2 & a,int lambda)
{
    return (make_Vect2(lambda*a.x, lambda*a.y));
}

