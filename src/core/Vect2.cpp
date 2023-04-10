#include <math.h>
#include <iostream>
#include "Vect2.h"

using namespace std;

Vect2 make_Vect2 (int x, int y )
 {
     Vect2 v;
     v.x = x;
     v.y = y ;
     return v;
 }

int distance( const Vect2 & a,const Vect2 & b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
Vect2 operator+(const Vect2 & a, const Vect2 &b)
{
    return(make_Vect2(a.x+b.x,a.y+b.y));
}

Vect2 operator-(const Vect2& a, const Vect2& b)
{
   return(make_Vect2(a.x-b.x,a.y-b.y));
}

Vect2 operator*(int lambda, const Vect2& a)
{
    return (make_Vect2(a.x*lambda, a.y*lambda));
}

Vect2 operator*( const Vect2 & a,int lambda)
{
    return (make_Vect2(lambda*a.x, lambda*a.y));
}

