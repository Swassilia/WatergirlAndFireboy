#ifndef _JEU
#define _JEU
#include "Personnage.h"
#include "Plateau.h"
#include "Vect2.h"

class Jeu
{

public:
    unsigned int score;
    /**
     * @brief Constructeur de la classe Jeu
     * 
     */
    Jeu();

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

    /************************************************************************/
    
    /**
     * @brief recupère les actions du clavier faite par le joueur
     * 
     * @return true si la touche est réalisée
     * @return false si non
     */
    bool ActionClavier(const char touche);

    /**
     * @brief permet les actions automatiques des obstacles de type Bloc
     * 
     */
    void ActionAuto(const Plateau &pla);

    /**
     * @brief un booléen qui retourne vrai si le calcule de collision entre les objets définie
    * en paramètres convient
     * On va tester la collision entre 
     * Personnage et Bonus:
     *  Personnage type eau avec Bonus type DiamondE
     *  Personnage type feu avec Bonus type DiamondF
     * Personnage et Obstacle:
     *  Personnage type eau avec Obstacle type Lava
     *  Personnage type feu avec Obstacle type Riviere
     *Ainsi tester toutes ces collision sur le plateau
     * @param per Personnage
     * @param obj Ob
     * @return true 
     * @return false 
     */
    bool collisionRivE(const Personnage& per,const Objet & obj);
        /**
     * @brief un booléen qui retourne vrai si le calcule de collision entre les objets définie
    * en paramètres convient
     * On va tester la collision entre 
     * Personnage et Bonus:
     *  Personnage type eau avec Bonus type DiamondE
     *  Personnage type feu avec Bonus type DiamondF
     * Personnage et Obstacle:
     *  Personnage type eau avec Obstacle type Lava
     *  Personnage type feu avec Obstacle type Riviere
     *Ainsi tester toutes ces collision sur le plateau
     * @param per Personnage
     * @param obj Ob
     * @return true 
     * @return false 
     */
    bool collisionRivF(const Personnage& per,const Objet & obj);
        /**
     * @brief un booléen qui retourne vrai si le calcule de collision entre les objets définie
    * en paramètres convient
     * On va tester la collision entre 
     * Personnage et Bonus:
     *  Personnage type eau avec Bonus type DiamondE
     *  Personnage type feu avec Bonus type DiamondF
     * Personnage et Obstacle:
     *  Personnage type eau avec Obstacle type Lava
     *  Personnage type feu avec Obstacle type Riviere
     *Ainsi tester toutes ces collision sur le plateau
     * @param per Personnage
     * @param obj Ob
     * @return true 
     * @return false 
     */
    bool collisionDiamE(const Personnage& per,const Objet & obj);
        /**
     * @brief un booléen qui retourne vrai si le calcule de collision entre les objets définie
    * en paramètres convient
     * On va tester la collision entre 
     * Personnage et Bonus:
     *  Personnage type eau avec Bonus type DiamondE
     *  Personnage type feu avec Bonus type DiamondF
     * Personnage et Obstacle:
     *  Personnage type eau avec Obstacle type Lava
     *  Personnage type feu avec Obstacle type Riviere
     *Ainsi tester toutes ces collision sur le plateau
     * @param per Personnage
     * @param obj Ob
     * @return true 
     * @return false 
     */
    bool collisionDiamF(const Personnage& per,const Objet & obj);

    /**
     * @brief Ajoute +1 au Score si la collision entre Personnage et bonus retourne Vrai
     * 
     * @param bon Bonus (DiamondF et DiamondE)
     * @param per Personnage (feu et eau)
     */

    /**
     * @brief un booléen qui retourne vrai si la partie a été réussie
     * 
     * @return true 
     * @return false 
     */
    bool succes(const Personnage& per, const Objet& obj);

    /**
     * @brief un booléen qui retourne vrai si la partie n'a pas été réussie
     * 
     * @return true 
     * @return false 
     */
    bool perte(const Personnage& per, const Objet& obj);

    /**
     * @brief Teste le focntionnement de l'ensemble des fonction de la classe
     * 
     */
    void testRegressionJeu();
    
    private:
    Plateau pla;
    Personnage feu;
    Personnage eau;

    Objet ob;
    
};

#endif