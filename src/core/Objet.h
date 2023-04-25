#ifndef _Objet
#define _Objet
//#include "Plateau.h"
#include "Type.h"
#include "Vect2.h"

class Objet {

    public:
    

    Objet();

    Objet(const Type& t, unsigned int posx, unsigned int posy);

    ~Objet();

    Vect2 getPos()const;
    void setPos(const unsigned int x, const unsigned int y);
    Type getType() const;
    void setType(const Type & t );

    int dir;

    private:

    Type typeO; //le type de l'objet

    Vect2 posO; //position de l'objet

   

};
#endif
