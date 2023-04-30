/**
@brief Module gérant les vecteurs du jeu
@file Vect2.h
@date 2023/03/14
*/
#ifndef _Vect2
#define _Vect2

/** 
 * @brief définir le type Vect2 via une structure
*/
struct Vect2
{
    int x, y;   // coordonnées
};

/**
 * @brief constructeur par copie de vecteur
 * 
 * @param x int
 * @param y int
*/
Vect2 make_Vect2 (int x, int y );

/**
 * @brief Calcule la distance entre deux vecteur2D
 * 
 * @param a Vcet2
 * @param b Vect2
*/
int distance( const Vect2 & a ,const Vect2& b);

/**
 * @brief Surcharge de l'Operateur + entre deux vecteurs
 * 
 * @param a Vect2
 * @param b Vect2
*/
Vect2 operator+(const Vect2& a, const Vect2 &b);

/**
 * @brief Surcharge de l'Operateur - entre deux vecteurs
 * 
 * @param a Vect2
 * @param b Vect2
*/
Vect2 operator-(const Vect2& a, const Vect2& b);

/**
 * @brief Surcharge de l'Operateur produit d'un vecteur et d'un entier
 * 
 * @param lambda int
 * @param a Vect2
*/
Vect2 operator*( const Vect2 &a, const int lambda);

/**
 * @brief Surcharge de l'Operateur produit d'un entier et d'un vecteur
 * 
 * @param lambda  int
 * @param a Vect2
*/
Vect2 operator*(int lambda, const Vect2 & a); 

#endif 


