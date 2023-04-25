 /**
@brief Module gérant les personnages du jeu
@file Personnage.h
@date 2023/03/14
*/

#ifndef _Personnage
 #define _Personnage
 #include "Vect2.h"
 #include "Type.h"
 #include "Plateau.h"

 /**
@brief Un personnage définit avec son type (eau ou feu), sa position sur le plateau, son nom et le plateau où il se trouve
*/
class Personnage
{

public:

    /**
     * @brief Constructeur par defaut
     * 
     */
    Personnage();

    /** @brief constructueur qui definit le type (obligatoire) et la position
     * @param t type du personnage
     * @param x la position en x 
     * @param y la position en y 
    */
    Personnage(const Type & t, int x, int y);
    
    // /** @brief destructeur du personnage*/
     ~Personnage();
       
    /**
     * @brief recupere les coordonnées du personnage
     * @return un Vect2 donc un x et y
     * 
    */
    Vect2 getPos()const;

    /**
     * @brief modifie les coordonnées du personnage
     * @param x unsigned int
     * @param y unsigned int
    */
    void setPos(const unsigned int x, const unsigned int y);

    /**
     * @brief permet de donner un nom au personnage
     * 
    */
    void entrernom();

    /**
     * @brief recupère le type d'un personnage
     * 
     * @return Type (soit feu ou eau)
     */
    Type getType()const;

    /**
     * @brief se deplacer à droite
     * @def augmente la valeur en position x
     * @param pla Plateau
    */
    void  DeplacerD (const  Plateau &pla);

    /**
     * @brief se deplacer à gauche
     * @def diminue la valeur en position x
     * @param pla Plateau
    */
    void  DeplacerG ( const  Plateau &pla);

    /**
     * @brief se deplacer ("tomber") en bas (gravité)
     * @def augmente la valeur en position y
     * @param pla Plateau
     */
    void  Gravite( const  Plateau &pla);

    /**
     * @brief se deplacer en haut 
     * @def diminue la valeur en position y
     * @param pla Plateau
    */
    void  DeplacerH ( const  Plateau &pla);
    
    void testRegression_Per();
    
private:

    Vect2 pos;  //position du personne de type Vect2 (vecteur)

    char * nom; //pointeur sur un tableau de char pour y entrer le nom du personnage

    Type type_p; //type du personnage (ici, soit feu ou eau)

    Plateau pla;    //plateau sur lequel se trouve les personnages

};



 #endif
