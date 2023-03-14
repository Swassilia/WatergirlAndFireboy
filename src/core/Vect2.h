#ifndef _Vect2
#define _Vect2

struct Vect2
{
    int x, y;// coordonnées
};

/**
 * @brief Operateur = entre deux vecteurs
 * @param a 
 * @param b 
*/

Vect2 make_Vect2 (int x, int y );
/**
 * @brief Calcule la distance entre deux vecteur2D
 * @param a 
 * @param b 
*/
int distance( const Vect2 & a ,const Vect2& b);

/**
 * @brief Operateur + entre deux vecteurs
 * @param a 
 * @param b 
*/
Vect2 operator+(const Vect2& a, const Vect2 &b);

/**
 * @brief Operateur - entre deux vecteurs
 * @param a 
 * @param b 
*/
Vect2 operator-(const Vect2& a, const Vect2& b);
/**
 * @brief Calcule produit un vecteur et un entié
 * @param lambda 
 * @param a
*/
Vect2 operator*( const Vect2 &a, const int lambda);
/**
 * @brief Calcule produit un vecteur et un entié
 * @param lambda 
 * @param a 
*/
Vect2 operator*(int lambda, const Vect2 & a); 




#endif 


