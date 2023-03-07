struct Vect2
{
    float x, y;
};
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
Vect2 operator-(Vect2 a, Vect2 b);
Vect2 operator*(int lambda, Vect2 b);
Vect2 operator*( Vect2 b, int lambda);
Vect2 operator*(int lambda, Vect2 b);









