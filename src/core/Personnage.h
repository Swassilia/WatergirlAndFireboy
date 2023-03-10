 #ifndef _Personnage
 #define _Personnage
 #include "Vect2.h"
 #include "Type.h"
 #include "Plateau.h"
class Personnage
{
private:
    Vect2 pos;
    Vect2 dir; 
    char * nom;
    char * prenom;
    Type type_p;
    bool vivant;
public:
    /** @brief constructueur qui definit le type (obligatoire)
     * @param t type du personnage
    */
    Personnage(const Type & t, float x, float y);

    /** @brief destructeur*/
    ~Personnage();

    /** @brief Déplace le personnage
     
    */

    
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
    void  DeplacerD ( );
    void  DeplacerG ();
    void  DeplacerH ( );
    Type getType();
    

};



 #endif
