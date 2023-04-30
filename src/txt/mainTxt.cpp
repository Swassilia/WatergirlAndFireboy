#include <iostream>
#include "WinTxt.h"
#include "JeuTxt.h"
#include "../core/Jeu.h"
#include <unistd.h>

/**
 * @brief  implémente le programme principal pour jouer au jeu en mode texte. 
 * @brief Il commence par effacer le terminal avec la fonction termClear(), puis crée une instance de la classe Jeu. 
 * @brief Ensuite, il appelle la fonction MontxtBoucle(jeu) pour lancer la boucle de jeu en mode texte.
 * @brief Enfin, il retourne 0 pour signaler que le programme s'est terminé avec succès
*/
int main(int argc, char** argv){
    termClear();
    Jeu jeu;
    MontxtBoucle(jeu);

    return 0;
}