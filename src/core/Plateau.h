/**
@brief Module gérant le Plateau de jeu
@file Plateau.h
@date 2023/03/14
*/

#ifndef _Plateau
#define _Plateau
#include "NomCase.h"
#include "Objet.h"

/**
@brief Un plateau = un tableau contenant des obstacles et des bonus entre des murs
*/

class Plateau
{

public:

    /**
     * @brief constructeur par defaut
    */
    Plateau();

    /**
     * @brief destructeur
    */
    ~Plateau();

    /**
     * @brief Mutateur : redéfinit une case du plateau
     * 
     * @param v Vect2
     * @param n NomCase
    */
    void setPlateau(const Vect2 &v,const NomCase &n);

    /**
     * @brief Accesseur : récupère la dimension en x du plateau
     * 
     * @return un entier
    */
    int getDimx()const;
    
    /**
     * @brief Accesseur : récupère la dimension en y du plateau
     * 
     * @return un entier
    */
    int getDimy()const;

    /**
     * @brief Accesseur : recupere la case du plateau dans les coordonnees x et y
     * @brief pour savoir ce qu'il y a dedans
     * 
     * @param x int
     * @param y int
     * 
     * @return NomCase
    */
    NomCase getPlateau (const int x, const int y) const;

    /**
     * @brief Accesseur : recupere l'objet dans le tableau d'objet des coordonnees x et y
     * 
     * @param x int
     * 
     * @return Obstacle de type Objet
    */
    Objet getObjet (const int x);

    /**
     * @brief Mutateur : redéfinit un objet dans le tableau d'objet
     * 
     * @param i int
     * @param t Type
    */
    void setObjet(int i, const Type &t);

    /**
     * @brief  verifier si une position est valide (libre) dans le plateau aux coordonees x et y
     * 
     * @param x int
     * @param y int
     * 
     * @return un booléen
    */
    bool EstPosValide(const int x, const int y)const;

    /**
     * @brief permet de bouger les blocs dans le plateau
     */
    void bougeAuto();

    /**
     * @brief donnée membre tableau 2D qui contient les éléments du plateau de type NomCase
     */  
    NomCase plateau[50][50];

  private:
    
    /**
     * @brief donnée membre tableau 2D qui contient les éléments du plateau de type NomCase
     */
    int dimx, dimy;

    /**
     * @brief donnée membre tableau qui contient les objets du plateau de type Objet
     */
    Objet tabObj [30];

    /**
     * @brief donnée membre tableau qui contient les blocs du plateau de type Objet
     */
    Objet tabBloc [4];

    /**
     * @brief donnée membre vitesse des objets en mouvement sur le plateau
     */
    int vitesse;

};
#endif
