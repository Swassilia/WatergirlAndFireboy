/**
@brief Module gérant le Plateau de jeu
@file Plateau.h
@date 2023/03/14
*/

#ifndef _Plateau
#define _Plateau
#include "Bonus.h"
#include "Obstacle.h"
#include "NomCase.h"
/**
@brief Un plateau = un tableau contenant des obstacles et des bonus entre des murs
*/
class Plateau
{
private:

    int dimx, dimy;

    Obstacle tabO [31][15];    //tableau d'obstacle //comment faire pour utiliser dimx et dimy
    // string fileName;
    Bonus * tabB;       //tableau de bonus

    NomCase plateau[50][50];    //plateau contenant tous les éléments 
                                //mais définis avec des noms,
                                //exemple: OBS pour obstacle...

public:

    /**
     * @brief constructeur par defaut
    */
    Plateau();

    /**
     * @brief destructeur
    */
    ~Plateau();

    void placerObstacle();
    void placerBonus();

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
                          pour savoir ce qu'il y a dedans
     * 
     * @return NomCase
    */
    NomCase getPlateau (const int x, const int y) const;

    /**
     * @brief Accesseur : recupere l'obstacle dans le tableau d'obstacle des coordonnees x et y
     * 
     * @return Obstacle
    */
    Obstacle getObstacle (const int x, const int y);

    /**
     * @brief Accesseur : recupere le bonus dans le tableau d'obstacle des coordonnees x et y
     * 
     * @return Obstacle
    */
    Bonus getBonus (const int x, const int y);

    /**
     * @brief  verifier si une position est valide (libre) dans le plateau aux coordonees x et y
    */
    bool EstPosValide(const int x, const int y);

    /**
     * @brief  verifier si une position est valide (libre) dans le plateau aux coordonees x et y
    */
    void mangeBonus(const int x, const int y); 
     
    /**
     * @brief Teste le focntionnement de l'ensemble des fonction de la classe
     * 
     */
    void testRegression_Pla();
};
#endif
