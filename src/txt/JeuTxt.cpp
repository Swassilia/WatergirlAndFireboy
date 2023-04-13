#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "JeuTxt.h"
// #include "../core/Jeu.h"
#include <iostream>
using namespace std;


 void txtAff(WinTXT & win, const Jeu & jeu) { 
	win.draw();
 	const Plateau& pla = jeu.getPlateau();
 	const Personnage& feu = jeu.getPersonnageFeu();
    const Personnage& eau = jeu.getPersonnageEau();
	//const Objet& ob  = jeu.getObjet();

	win.draw();
     // Affichage des murs et des pastilles
 	for(int x=0;x<pla.getDimx();++x)
 		for(int y=0;y<pla.getDimy();++y)
 			win.print( x, y, pla.getPlateau(x,y));

     // Affichage de fire boy
 	win.print(feu.getPos().x,feu.getPos().y,'f');

 	// Affichage du water girl
 	win.print(eau.getPos().x,eau.getPos().y,'e');

	//.print(ob.getPos().x,ob.getPos().y,'__');	
 	win.draw();
	
 }




 void MontxtBoucle (Jeu & jeu) {
 	// Creation d'une nouvelle fenetre en mode texte
 	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getPlateau().getDimx(),jeu.getPlateau().getDimy());

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
 		//jeu.ActionAuto(jeu.getPlateau());
 		 c = win.getCh();
		Plateau pla=jeu.getPlateau();
		jeu.ActionClavier(c);
		// if (jeu.collisionRivE(jeu.getPersonnageEau(),pla.getObjet(0)))
		// {
		// 	cout<<"z"<<endl;
		// }
		 if (c=='a')
		 {
			cout<<endl;
		 	cout<< "Vous avez bien quitté"<<endl;
			ok=false;
		 }
		for (int i=1; i<=30; i++)
		{
			if (jeu.succes(pla.getObjet(i-1),pla.getObjet(i%30)))
			{
				cout<<endl;
				cout<<"bravo"<<endl;
				ok=false;
			}
			if (jeu.perte(pla.getObjet(i-1)))
		 	{
			cout<<endl;
		 	cout<< "Vous avez bien quitté"<<endl;
			ok=false;
			 }
		}
 	} while (ok);
 }