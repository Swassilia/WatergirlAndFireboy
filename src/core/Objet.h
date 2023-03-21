#ifndef _Objet
#define _Objet
#include "Type.h"
#include "Vect2.h"

class Objet {
    private:

    Type typeO; //le type de l'objet

    Vect2 posO; //position de l'objet

    public:

    Objet();

    Objet(const Type& t, unsigned int posx, unsigned int posy);

    ~Objet();

    Vect2 getPos()const;

    Type getType() const;


};
#endif
