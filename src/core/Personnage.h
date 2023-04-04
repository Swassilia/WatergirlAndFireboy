 #ifndef _Personnage
 #define _Personnage
 #include "Vect2.h"
 #include "Type.h"
class Personnage
{
private:
    /** 
     * 
    */
    Vect2 pos;
    Vect2 dir; 
    char * nom;
    Type type_p;
    // string nomF;
    bool vivant;
public:

    /**
     * @brief Constructeur par defaut
     * 
     */
    Personnage();
    /** @brief constructueur qui definit le type (obligatoire)
     * @param t type du personnage
     * @param x la position en x 
     * @param y la position en y 
    */
    Personnage(const Type & t, int x, int y);
    
    // /** @brief destructeur*/
     ~Personnage();
       
    /**
     * @brief recupere les coordonnées 
     * @return un Vect2 donc un x et y
     * 
    */
    Vect2 getPos()const;
    /**
     * @brief permet d'entrer le nom et prenom de l'utilisateur
     
     * 
    */
    void entrernom();
    /**
     * @brief recupère le type d'un personnage
     * 
     * @return Type recupère du enume Type les types feu et eau 
     */
    Type getType()const;
    /**
     * @brief se deplacer a droite
     * @def augmente la valeur en position x
     * 
    */
    void  DeplacerD ( );
    /**
     * @brief se deplacer a gauche
     * @def diminue la valeur en position x
     * 
    */
    void  DeplacerG ();
    /**
     * @brief se deplacer en bas (gravité)
     * 
     */
    void  Gravite();
    /**
     * @brief se deplacer en haut 
     * @def augmente la valeur en position y
     * 
    */
    void  DeplacerH ();
    
    void testRegression_Per();

};



 #endif
