#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Menu.h"

//compléter ces procédure avec a fonction qu'on veut executer, genre sdl ou txt ?

void affModeTxt()
{
	printf("Jeu mode texte\n");
    fflush(stdout);
    system("bin/text");
}

void affModeSDL()
{
	printf("Jeu mode SDL\n");
	fflush(stdout);
    system("bin/sdl");

}


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