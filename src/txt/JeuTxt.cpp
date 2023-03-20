#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "WinTxt.h"

#include "JeuTxt.h"
#include "../core/Jeu.h"
#include <iostream>
using namespace std;


 void txtAff(WinTXT & win, const Jeu & jeu) {
	win.clear();
	//win.print(5, 5, 't');
	win.draw();
 	const Plateau& pla = jeu.getPlateau();
 	const Personnage& feu = jeu.getPersonnageFeu();
     const Personnage& eau = jeu.getPersonnageEau();
 	//Obstacle *tabO;
 	win.clear();
	//win.print(5, 5, 't');
	win.draw();
     // Affichage des murs et des pastilles
 	for(int x=0;x<pla.getDimx();++x)
 		for(int y=0;y<pla.getDimy();++y)
 			win.print( x, y, pla.getPlateau(x,y));
     // Affichage de fire boy
 	win.print(feu.getPos().x,feu.getPos().y,'F');
 	// Affichage du water girl
 	win.print(eau.getPos().x,eau.getPos().y,'E');	
 	win.draw();
	
 }


/*void toto(void) {
	std::cout << "Toto fait du vélo :D" << std::endl<< std::endl<< std::endl;
}*/

 void MontxtBoucle (Jeu & jeu) {
 	// Creation d'une nouvelle fenetre en mode texte
 	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getPlateau().getDimx(),jeu.getPlateau().getDimy());

    //std::cout << "Toto fait du vélo :D" << std::endl<< std::endl<< std::endl;
	//exit(-1);

    /*termClear();
    WinTXT win (40, 40);
    win.print(5, 5, "toto");
    win.draw();
    sleep(1000);
    termClear();
    exit(-1);

*/

 	bool ok = true;
 	int c;
 	do {
		termClear();
 	    txtAff(win,jeu);
        #ifdef _WIN32
        Sleep(100);
 		#else
 		usleep(100000);
        #endif // WIN32
 		//jeu.ActionAuto();
		
 		 c = win.getCh();
		 jeu.ActionClavier(c);
		 
		 if (c=='a')
		 {
			cout<<endl;
		 	cout<< "Vous avez bien quitté"<<endl;
			ok=false;
		 }
 	} while (ok);
 }