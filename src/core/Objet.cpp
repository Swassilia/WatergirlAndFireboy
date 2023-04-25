#include <math.h>
#include <iostream>

#include "Objet.h"

using namespace std;
 
Objet::Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}

Objet::Objet(const Type& t, const unsigned int x, const unsigned int y){

    typeO = t;
    posO.x=x;
    posO.y=y;

}

Objet::~Objet(){

    typeO = Defaut;
    posO= make_Vect2(0,0);

}
Vect2 Objet::setPos(const unsigned int x, const unsigned int y){
    posO.x = x;
    posO.y = y;
}
Vect2 Objet::getPos()const  {

    return posO;
}

Type Objet::getType()const  {

    return typeO;
}

//  void Objet::bougeAuto(const Plateau & pla){
//      int dx [4] = { 0, 1, 0, 1};
//      int dy [4] = { 0, -1, 0, -1};
//      int xtmp,ytmp;
  
//      xtmp = posO.x - dx[dir];
//      ytmp = posO.y - dy[dir];
//      if (pla.EstPosValide(xtmp,ytmp)) {
//          cout<<"ici"<<endl;
//          posO.x = +xtmp;
//          posO.y = +ytmp;
//      }else dir = rand()%4;
//  }