 #ifndef _Personnage
 #define _Personnage
 #include "Vect2.h"
 #include "Type.h"
 #include "Plateau.h"
class Personnage
{
private:
    /** 
     * 
    */
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
    Personnage(const Type & t);

    /** @brief destructeur*/
    ~Personnage();

    /** @brief Déplace le personnage
     * @param p
     * @param n 
     * 
    */
    void deplacer (const Plateau & p, int n );
    
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
     * @brief recupere la coordonnée y
     * @return la valeur de y (float)
     * 
    */
    void sauter();
    /**
     * @brief recupere la coordonnée y
     * @return la valeur de y (float)
     * 
    */
    void entrernom();
    
    

};



 #endif