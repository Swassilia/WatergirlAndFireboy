/**
@brief Module gérant les obstacles
@file Obstacle.h
@date 2023/03/13
*/

#ifndef _Obstacle
#define _Obstacle
#include "Type.h"
#include "Vect2.h"
#include "Plateau.h"
/**
@brief Un obstacle = un objet typé avec une position 2D et une direction
*/
class Obstacle
{

private:

    Vect2 pos; //vecteur position 2D de l'obstacle

    int dir; //direction de l'obstacle pour les mouvements 

public:
    Type type_ob; //type de l'obstacle

    /**
     * @brief constructeur par defaut
    */
    Obstacle();
    /**
     * @brief constructeur initialise type_ob et pos avec les paramètres:
     * \param t type à initialiser
     * \param posx position en x à initialiser
     * \param posy position en y à initialiser
    */ 
    Obstacle(Type t, unsigned int x, unsigned int y);

    /**
     * @brief destructeur
    */
    ~Obstacle();

    /**
     * @brief Accesseur : récupère la position de l'obstacle
     * 
     * @return un vecteur compris entre les dimensions du plateau
    */
    Vect2 getPos();
    
    /**
     * @brief procédure qui déplace un bloc automatiquement
     * \param p donnée référence à la classe Plateau
    */
    void bougeAuto(const Plateau &p);

};


#endif