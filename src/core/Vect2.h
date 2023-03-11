#ifndef _Vect2
#define _Vect2

struct Vect2
{
    float x, y;
};

/**
 * @brief Operateur = entre deux vecteurs
 * @param a 
 * @param b 
*/

Vect2 make_Vect2 (float x, float y );
/**
 * @brief Calcule la distance entre deux vecteur2D
 * @param a 
 * @param b 
*/
float distance( const Vect2 & a ,const Vect2& b);

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
Vect2 operator*( const Vect2 &a, const float lambda);
/**
 * @brief Calcule produit un vecteur et un entié
 * @param lambda 
 * @param a 
*/
Vect2 operator*(int lambda, const Vect2 & a); 




#endif 


