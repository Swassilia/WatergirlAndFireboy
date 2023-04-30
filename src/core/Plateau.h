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

    //void placerObstacle();
   // void placerBonus();

    void setPlateau(const Vect2 &v);
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
     * @brief Accesseur : recupere l'objet dans le tableau d'objet des coordonnees x et y
     * 
     * @return Obstacle
    */
    Objet getObjet (const int x);

    void setObjet(int i, const Type &t);


    /**
     * @brief  verifier si une position est valide (libre) dans le plateau aux coordonees x et y
    */
    bool EstPosValide(const int x, const int y)const;

    /**
     * @brief permet de bouger les objets dans le plateau
     * 
     * @param ob appel de l'objet à bouger
     */
    void bougeAuto();
    /**
     * @brief Set the Plateau object
     * 
     * @param v 
     * @param n 
     */
    
      

  private:
    NomCase plateau[50][50];  //plateau contenant tous les éléments 
    int dimx, dimy;
    Objet tabObj [30];
    Objet tabBloc [4];
    int vitesse;

};
#endif
