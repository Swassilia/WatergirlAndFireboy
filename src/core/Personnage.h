 #ifndef _Personnage
 #define _Personnage
 #include "Vect2.h"
 #include <string>
 #include "Type.h"
 #include "Plateau.h"
class Personnage
{
private:
    /** */
    Vect2 pos;
    Vect2 dir; 
    string nom, prenom;
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
    void deplacer (Plateau p, int n );
    
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
    Void sauter();
    void entrernom();
    

};





 #endif