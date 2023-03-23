/**
@brief Module gérant les obstacles
@file Obstacle.h
@date 2023/03/13
*/

#ifndef _Obstacle
#define _Obstacle
// #include "Type.h"
// #include "Vect2.h"
#include "Objet.h"

/**
@brief Un obstacle = un objet typé avec une position 2D et une direction
*/
class Obstacle
{
private:

    //Vect2 pos;      //vecteur position 2D de l'obstacle
    //Type type_ob;   //type de l'obstacle
    
    int dir;        //direction de l'obstacle pour les mouvements 
    Objet idO;

public:

    /**
     * @brief constructeur par defaut
    */
    Obstacle();

    /**
     * @brief destructeur
    */
    ~Obstacle();

    /**
     * @brief constructeur initialise type_ob et pos avec les paramètres:
     * \param t type à initialiser
     * \param posx position en x à initialiser
     * \param posy position en y à initialiser
    */ 
    Obstacle(const Type& t, unsigned int x, unsigned int y);

    Objet getObjet();
    // /**
    //  * @brief Accesseur : récupère la position de l'obstacle
    //  * 
    //  * @return un vecteur compris entre les dimensions du plateau
    // */
    // Vect2 getPos()const;

    //  /**
    //  * @brief Accesseur : récupère le type de l'obstacle
    //  * 
    //  * @return un type
    // */
    // Type getType()const;


};

#endif