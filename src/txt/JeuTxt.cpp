#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "WinTxt.h"

#include "Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Plateau& pla = jeu.getPlateau();
	const Personnage& feu = jeu.getPersonnageFeu();
    const Personnage& eau = jeu.getPersonnageEau();
	Obstacle *tab;
	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<pla.getDimx();++x)
		for(int y=0;y<pla.getDimy();++y)
			win.print( x, y, pla.getXY(x,y));

    // Affichage de fire boy
	win.print(feu.getPos().x,feu.getPos().y,'F');
	// Affichage du water girl
	win.print(eau.getPos().x,eau.getPos().y,'E');

	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getPlateau().getDimx(),jeu.getPlateau().getDimy());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		jeu.ActionAuto();

		c = win.getCh();
		switch (c) {
			case 'k':
				jeu.ActionClavier('g');
				break;
			case 'm':
				jeu.ActionClavier('d');
				break;
			case 'l':
				jeu.ActionClavier('h');
				break;
			case 'o':
				jeu.ActionClavier('b');
				break;
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}