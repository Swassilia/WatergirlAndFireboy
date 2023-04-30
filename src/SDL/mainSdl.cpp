#include "JeuSdl.h"

/**
 * @brief instance de la classe SDLSimple appelée sj et appelle la méthode sdlBoucle de cet objet. 
 * @brief Cette méthode lance la boucle principale de SDL qui gère les événements et met à jour l'affichage de la fenêtre jusqu'à ce que l'utilisateur ferme la fenêtre ou que le programme se termine. 
 * @brief Ainsi, ce code initialise et lance une interface graphique SDL pour exécuter un jeu
*/
int main (int argc, char** argv) {

	SDLSimple sj; //instancier un objet SDLSimple
	sj.sdlBoucle();
	return 0;
}
