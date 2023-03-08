#ifndef _Vect2
#define _Vect2

struct Vect2
{
    float x, y;
};

Vect2 make_Vect2 (float x, float y );
/**
 * @brief Calcule la distance entre deux vecteur2D
 * @param a 
 * @param b 
*/
float distance( Vect2 a ,Vect2 b);

/**
 * @brief Calcule la distance entre deux vecteur2D
 * @param a 
 * @param b 
*/
Vect2 operator+(Vect2 a, Vect2 b);

/**
 * @brief Calcule la difference entre deux Vecteur2D
 * @param a 
 * @param b 
*/
Vect2 operator-(Vect2 a, Vect2 b);
/**
 * @brief Calcule produit un vecteur et un entié
 * @param lambda 
 * @param a
*/
Vect2 operator*( Vect2 a, float lambda);
/**
 * @brief Calcule produit un vecteur et un entié
 * @param lambda 
 * @param a 
*/
Vect2 operator*(int lambda, Vect2 a);




#endif 


