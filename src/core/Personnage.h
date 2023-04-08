 #ifndef _Personnage
 #define _Personnage
 #include "Vect2.h"
 #include "Type.h"
 #include "Plateau.h"
class Personnage
{

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
    void  DeplacerD (const  Plateau &pla);
    /**
     * @brief se deplacer a gauche
     * @def diminue la valeur en position x
     * 
    */
    void  DeplacerG ( const  Plateau &pla);
    /**
     * @brief se deplacer en bas (gravité)
     * 
     */
    void  Gravite( const  Plateau &pla);
    /**
     * @brief se deplacer en haut 
     * @def augmente la valeur en position y
     * 
    */
    void  DeplacerH ( const  Plateau &pla);
    
    void testRegression_Per();
    
private:

    /** 
     * 
    */
    Vect2 pos;
    char * nom;
    Type type_p;
    // string nomF;
    bool vivant;
    Plateau pla;

};



 #endif
