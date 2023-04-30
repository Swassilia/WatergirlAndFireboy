#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Menu.h"

//fonction qui appellera l'éxécutable text pour afficher le jeu en mode texte
void affModeTxt()
{
	printf("Jeu mode texte\n");
    fflush(stdout);
    system("bin/text");
}

//fonction qui appellera l'éxécutable sdl pour afficher le jeu en mode sdl
void affModeSDL()
{
	printf("Jeu mode SDL\n");
	fflush(stdout);
    system("bin/sdl");

}

//fonction main pour afficher le mode choisi par rapport au choix de l'utilisateur
int main()
{
	ChoixMenu cm;
	do
	{
		menuAff();
		cm = menuQuestion();
		switch(cm)
		{
			case MENU_Choix1 : affModeTxt(); break;
			case MENU_Choix2 : affModeSDL(); break;
			case MENU_Quit: break;
			default: printf("Choix non trait par le programme\n");
		}
		fflush(stdout);
	} while(cm!=MENU_Quit);

	return 0;
}
