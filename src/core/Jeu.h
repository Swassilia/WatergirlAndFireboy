/**
@brief Module gérant les fonctionnalités du jeu
@file Jeu.h
@date 2023/03/14
*/
#ifndef _JEU
#define _JEU
#include "Personnage.h"
#include "Plateau.h"
#include "Objet.h"
#include "Vect2.h"
/**
@brief Un jeu = ensemble du plateau et ses fonctionnalités concernant les déplacements des personnages 
*/

class Jeu
{

public:
    /**
     * @brief Constructeur par défaut de la classe Jeu
     * 
     */
    Jeu();

    /**
     * @brief Accesseur de la classe, Recupère le Plateau
     * 
     * @return Plateau sans modifier ses données membres
     */
    const Plateau getPlateau()const;

    /**
     * @brief Accesseur de la classe qui Recupère le personnage de type eau
     *  
     * @return Personnage sans modifier ses données membres
     */
    const Personnage getPersonnageEau()const;

    /**
     * @brief Accesseur de la classe qui Recupère le personnage de type feu
     * 
     * @return Personnage sans modifier ses données membres
     */
    const Personnage getPersonnageFeu()const;

    /************************************************************************/
    
    /**
     * @brief recupère les actions du clavier faite par le joueur et déplace ces mêmes perso en fonction de la touche
     * 
     * @return true si la touche est préssée
     * @return false si non
     */
    bool ActionClavier(const char touche);

    /**
     * @brief fonction en plus qui gère la présence de gravité ou pas,
     * @brief on peut choisir d'enlever la gravité pour un niveau
     * 
     * @param vr booléen
     */ 
    void Gravite(bool vr);

    /**
     * @brief permet le mouvement automatique des obstacles de type Bloc
     * 
     */
    void ActionAuto();

    /**
    * @brief vérifier les collisions entre les objets et les personnages
    * 
    * @param per Personnage
    * @param obj Ob
    * 
    * @return true si le personnage et l'objet sont sur la même case
    * @return false si non
    */
    bool collision(const Personnage& per,const Objet & obj);
    
    /**
     * @brief vérifie si la partie est réussie, càd si les deux personnages sont en collision avec les portes (en même temps)
     * 
     * @return true 
     * @return false 
     */
    bool succes(const Objet & obj,const Objet & ob);

    /**
     * @brief tester si la partie est perdue en vérifiant la collision entre un personnage et un élément de type contraire
     *
     *  @return true si c'est perdu
     * @return false si non
     */
    bool perte(const Objet & obj);
    
    /**
     * @brief Ajoute +1 au Score si la collision entre Personnage et bonus retourne Vrai
     * 
     * @param pla Plateau (feu et eau)
     */
   void ajouteScore(Plateau &pla);

    /**
     * @brief Teste le fonctionnement de l'ensemble des fonctions de la classe
     * 
     */
    void testRegressionJeu();
    
    /**
     * @brief donnée membre concernant le temps de jeu
     */
    int tmp_partie;

    private:

    /**
     * @brief score du jeu
     */
    unsigned int score;

    /**
     * @brief le plateau de jeu
     */
    Plateau pla;        

    /**
     * @brief le personnage feu du jeu
     */
    Personnage feu;     

    /**
     * @brief le personnage eau du jeu
     */
    Personnage eau;   
    
};

#endif