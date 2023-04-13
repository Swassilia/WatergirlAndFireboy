#include <cstdio>
#include "Menu.h"

const int MENU_MAX = 4;

void menuAff()
{
	printf("\nMenu\n");
	printf("1: Jeu mode texte\n");
	printf("2: Jeu mode SDL\n");
	printf("0: Exit\n");
	printf("Votre choix?\n");
	fflush(stdout);
}


ChoixMenu menuQuestion()
{
	ChoixMenu cm;
	int i;
	char dum[32];
	bool ok=false;
	do
	{
		if (scanf("%d",&i)!=1) scanf("%s",dum);
		cm=((ChoixMenu)(i));
		if ((cm<0) || (cm>=MENU_MAX)) 
			printf("Erreur choix menu\n");
		else ok=true;
		fflush(stdout);
	} while(!ok);
	printf("\n"); fflush(stdout);
	return cm;
}
