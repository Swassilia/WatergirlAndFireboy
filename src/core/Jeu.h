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
     * @brief Recupère le Plateau
     * 
     * @return Plateau sans modifier ses données membres
     */
    const Plateau getPlateau()const;

    /**
     * @brief Recupère un personnage de type eau
     *  
     * @return Personnage sans modifier ses données membres
     */
    const Personnage getPersonnageEau()const;

    /**
     * @brief Recupère un personnage de type feu
     *  
     * @return Personnage sans modifier ses données membres
     */
    const Personnage getPersonnageFeu()const;

    // /**
    //  * @brief Recupère un bloc se trouvant sur le plateau 
    //  *  
    //  * @return Objet (type bloc) sans modifier ses données membres
    //  */
    // const Objet getBloc()const;

    /************************************************************************/
    
    /**
     * @brief recupère les actions du clavier faite par le joueur et déplace ces mêmes perso en fonction de la touche
     * 
     * @return true si la touche est préssée
     * @return false si non
     */
    bool ActionClavier(const char touche);

    /**
     * @brief 
     * 
     * @param vr 
     */ 
    void Gravite(bool vr);

    /**
     * @brief permet le mouvement automatique des obstacles de type Bloc
     * 
     */
    void ActionAuto();

    /**
     * @brief vérifier les collisions entre les objets et les personnages
    * @param per Personnage
    * @param obj Ob
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
     * @return true si c'est perdu
     * @return false si non
     */
    bool perte(const Objet & obj);
    
    /**
     * @brief Ajoute +1 au Score si la collision entre Personnage et bonus retourne Vrai
     * 
     * @param pla Plateau (feu et eau)
     */
    void ajouteScore(Plateau pla);

    /**
     * @brief Teste le focntionnement de l'ensemble des fonction de la classe
     * 
     */
    void testRegressionJeu();
    
    int tmp_partie; //temps de du jeu

    private:

    unsigned int score; //score du jeu
    Plateau pla;        //plateau du jeu
    Personnage feu;     //personnage feu du jeu
    Personnage eau;     //personnage eau du jeu
    //Objet bloc;
    
};

#endif