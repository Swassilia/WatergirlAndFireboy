/**
@brief Module gérant les Objets du jeu
@file Objet.h
@date 2023/03/14
*/
#ifndef _Objet
#define _Objet
#include "Type.h"
#include "Vect2.h"

/**
@brief Un Objet = identifié par un type, une position et une direction
*/
class Objet {

    public:

    /**
     * @brief Constructeur par défaut de la classe Objet
     * 
     */
    Objet();

    /**
     * @brief Constructeur par copie de la classe Objet
     * 
     * @param t Type
     * @param posx unsigned int
     * @param posy unsigned int
     */
    Objet(const Type& t, unsigned int posx, unsigned int posy);

    /**
     * @brief Destructeur de la classe Jeu
     * 
     */
    ~Objet();

    /**
     * @brief accesseur de la classe Objet pour résupérer la position de l'objet
     * 
     * @return un vecteur Vect2
     */
    Vect2 getPos()const;

    /**
     * @brief Mutateur de la classe Objet qui redéfinit la position de l'objet
     * 
     * @param x unsigned int x
     * @param y unsigned int y
     */
    void setPos(const unsigned int x, const unsigned int y);

    /**
     * @brief accesseur de la classe Objet pour récupérer le type de l'objet
     * 
     * @return un type Type
     */
    Type getType() const;

    /**
     * @brief mutateur de la classe Objet pour redéfinir le type de l'objet
     * 
     * @param t Type
     * 
     */
    void setType(const Type & t );

    /**
     * @brief direction de l'objet de type int
     * 
     */
    int dir;

    private:
    
    /**
     * @brief type de l'objet de type Type
     * 
     */
    Type typeO;

    /**
     * @brief position de l'objet de type Vect2
     * 
     */
    Vect2 posO; 

   

};
#endif
