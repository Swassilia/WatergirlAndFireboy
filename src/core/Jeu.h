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
    Jeu(Plateau pla);
    ~Jeu();
    Plateau getPlateau();
    Personnage getPersonnage();
    void ActionClavier();
    void ActionAuto();
    bool succe();
    bool perte();
    bool collision(Personnage per,Obstacle ob,Bonus bon,Plateau & pla);
    int calculColl(Vect2 a,Vect2 b);
    void AjoutScore(Bonus bon, Personnage per);
};
