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

    /** @brief constructueur par copie qui definit le type et la position
     * 
     * @param t type du personnage
     * @param x la position en x 
     * @param y la position en y 
    */
    Personnage(const Type & t, int x, int y);
    
     /** 
      * @brief destructeur du personnage
      */
     ~Personnage();
       
    /**
     * @brief Accesseur de la classe qui recupere les coordonnées du personnage
     * 
     * @return un Vect2 donc un x et y
     * 
    */
    Vect2 getPos()const;

    /**
     * @brief Mutateur de la classe qui modifie les coordonnées du personnage
     * 
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
     * @brief Accesseur de la classe qui recupère le type d'un personnage
     * 
     * @return Type (soit feu soit eau)
     */
    Type getType()const;

    /**
     * @brief se deplacer à droite
     * 
     * @def augmente la valeur en position x
     * 
     * @param pla Plateau
    */
    void  DeplacerD (const  Plateau &pla);

    /**
     * @brief se deplacer à gauche
     * 
     * @def diminue la valeur en position x
     * 
     * @param pla Plateau
    */
    void  DeplacerG ( const  Plateau &pla);

    /**
     * @brief se deplacer ("tomber") en bas (gravité)
     * 
     * @def augmente la valeur en position y
     * 
     * @param pla Plateau
     */
    void  Gravite( const  Plateau &pla);

    /**
     * @brief se deplacer en haut 
     * 
     * @def diminue la valeur en position y
     * 
     * @param pla Plateau
    */
    void  DeplacerH ( const  Plateau &pla);
    
    /**
     * @brief Teste le fonctionnement de l'ensemble des fonctions de la classe
     * 
     */
    void testRegression_Per();
    
private:

    /**
     * @brief donnée membre concernant la position des personnages
     */
    Vect2 pos;

    /**
     * @brief donnée membre pointeur sur un tableau de char pour y entrer le nom du personnage
     */
    char * nom;

    /**
     * @brief donnée membre concernant le type des personnages
     */
    Type type_p;

    /**
     * @brief donnée membre concernant plateau sur lequel se trouve les personnages
     */
    Plateau pla;

};

 #endif
