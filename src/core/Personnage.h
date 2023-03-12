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
    bool vivant;
public:
    /** @brief constructueur qui definit le type (obligatoire)
     * @param t type du personnage
     * @param x la position en x 
     * @param y la position en y 
    */
    Personnage(const Type & t, float x, float y);

    /** @brief destructeur*/
    ~Personnage();
       
    /**
     * @brief récupere la coordonnée x
     * @return la valeur de x (float)
     * 
    */
    float getX();
    /**
     * @brief recupere la coordonnée y
     * @return la valeur de y (float)
     * 
    */
    float getY();
    /**
     * @brief permet d'entrer le nom et prenom de l'utilisateur
     * @return la valeur de y (float)
     * 
    */
    void entrernom();
    /**
     * @brief recupère le type d'un personnage
     * 
     * @return Type recupère du enume Type les types feu et eau 
     */
    Type getType();
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
     * @brief se deplacer en haut 
     * @def augmente la valeur en position y
     * 
    */
    void  DeplacerH ( );
    

};



 #endif
