#ifndef _JEU
#define _JEU
#include "Personnage.h"
#include "Obstacle.h"
#include "Plateau.h"
#include "Bonus.h"
#include "Vect2.h"

class Jeu
{
private:
    Plateau pla;
    Personnage feu;
    Personnage eau;
    Obstacle *tab;
    unsigned int score;
    Bonus bon;
public:
    /**
     * @brief Constructeur de la classe Jeu
     * 
     */
    Jeu();

    /**
     * @brief Destructeur de la classe Jeu
     * 
     */
    ~Jeu();

    /**
     * @brief Recupère le Plateau
     * 
     * @return ne modifie pas la valeur de retour du plateau 
     */
    const Plateau getPlateau()const;

    /**
     * @brief Recupère un personnage
     * de type feu ou de type eau
     *  
     * @return ne modifie pas la valeur de retour de personnage 
     */
    const Personnage getPersonnageEau()const;

    const Personnage getPersonnageFeu()const;

    /**
     * @brief recupère les actions du clavier faite par le joueur
     * 
     * @return true si la touche est réalisée
     * @return false si non
     */
    bool ActionClavier();

    /**
     * @brief permet les actions automatiques des obstacles de type Bloc
     * 
     */
    void ActionAuto();

        // /**
        //  * @brief un booléen qui retourne vrai si le calcule de collision entre les objets définie
        //  * en paramètres convient
        //  * On va tester la collision entre 
        //  * Personnage et Bonus:
        //  *  Personnage type eau avec Bonus type DiamondE
        //  *  Personnage type feu avec Bonus type DiamondF
        //  * Personnage et Obstacle:
        //  *  Personnage type eau avec Obstacle type Lava
        //  *  Personnage type feu avec Obstacle type Riviere
        //  *Ainsi tester toutes ces collision sur le plateau
        //  * @param per Personnage
        //  * @param ob Obstacle
        //  * @param bon Bonus
        //  * @param pla Plateau
        //  * @return true 
        //  * @return false 
        //  */
        // bool collision(const Personnage per,const Obstacle ob,const Bonus bon,const Plateau & pla);

    bool collision(const Personnage per, bool t);

    bool collision_P_B(const Personnage per, const Bonus bon);
    /**
     * @brief Ajoute +1 au Score si la collision entre Personnage et bonus retourne Vrai
     * 
     * @param bon Bonus (DiamondF et DiamondE)
     * @param per Personnage (feu et eau)
     */
    void AjoutScore(const Bonus bon,const Personnage per);

    /**
     * @brief un booléen qui retourne vrai si la partie a été réussie
     * 
     * @return true 
     * @return false 
     */
    bool succe()const;

    /**
     * @brief un booléen qui retourne vrai si la partie n'a pas été réussie
     * 
     * @return true 
     * @return false 
     */
    bool perte(const Personnage per, const Obstacle ob)const;
};

#endif