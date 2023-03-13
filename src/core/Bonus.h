/**
@brief Module gérant les bonus
@file Bonus.h
@date 2023/03/13
*/

#ifndef _Bonus
#define _Bonus
#include "Vect2.h"
#include "Type.h"
/**
@brief Un Bonus = un diamant typé et sa position 2D
*/
class Bonus
{
private:

public:

    Vect2 pos; //vecteur position 2D du bonus 
    Type type_bon; //type du Bonus

    /**
        * @brief constructeur par défaut
    */
    Bonus();
    /**
     * @brief constructeur initialise type_bon et pos avec les paramètres:
     * \param t type à initialiser
     * \param posx position en x à initialiser
     * \param posy position en y à initialiser
    */ 
    Bonus(Type t, unsigned int posx, unsigned int posy );

    /**
     * @brief destructeur
    */
    ~Bonus();

};
#endif