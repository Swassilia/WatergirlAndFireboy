#ifndef _JEU
#define _JEU
#include "Personnage.h"
#include "Plateau.h"
#include "Vect2.h"

class Jeu
{

public:
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

    const Objet getBloc()const;
    const Objet getDiam()const;

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
    void ActionAuto();

    /**
     * @brief un booléen qui retourne vrai si le calcule de collision entre les objets définie
    * en paramètres convient
    *
    * On va tester la collision entre 
    * Personnage et un Objet
    * @param per Personnage
    * @param obj Ob
    * @return true 
    * @return false 
    */
    bool collision(const Personnage& per,const Objet & obj);
    bool collisionPorteE(const Personnage& per,const Objet & obj);
    bool collisionPorteF(const Personnage& per,const Objet & obj);
    
    /**
     * @brief Ajoute +1 au Score si la collision entre Personnage et bonus retourne Vrai
     * 
     * @param bon Bonus (DiamondF et DiamondE)
     * @param per Personnage (feu et eau)
     */
    void ajouteScore(const Plateau & pla);
    /**
     * @brief un booléen qui retourne vrai si la partie a été réussie
     * 
     * @return true 
     * @return false 
     */
    bool succes( const Objet& obj, const Objet& ob);

    /**
     * @brief un booléen qui retourne vrai si la partie n'a pas été réussie
     * @ on test les types puis les collisions associées
     * @return true 
     * @return false 
     */
    bool perte(const Objet & obj);

    /**
     * @brief Teste le focntionnement de l'ensemble des fonction de la classe
     * 
     */
    void testRegressionJeu();
    /**
     * @brief 
     * 
     * @param vr 
     */
    void Gravite(bool vr);

    private:
    unsigned int score;
    Plateau pla;
    Personnage feu;
    Personnage eau;
    Objet bloc;
    Objet diam;
    
};

#endif