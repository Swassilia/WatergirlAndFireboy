#include <cassert>
#include <iostream>
#include "Plateau.h"
using namespace std;

const char plateau1[15][32] = {
    "###############################", 
    "#  E       ########        F  #",
    "#######    ##########    ######",
    "#       ##          ###       #",
    "#    #########                #",
    "#  #################   ########",
    "#             ######          #",
    "#__           ###### __########",
    "############        ###########",
    "#            ######           #",
    "#   ########        ###########",
    "#            ######        ####",
    "##############    #####    ####",
    "#                       #######",
    "###############################",

    
};


Plateau::Plateau(){

    dimx=31;
    dimy=15;
    for(int y=0;y<dimy;++y)
        for(int x=0;x<dimx;++x)
		{
			switch(plateau1[dimy-1-y][x]) //revoir dans quel ordre sont stockés les éléments
			{
				case '#': plateau[x][y] = WALL; break;
				case '_': plateau[x][y] = BLOC; break; 
				case ' ': plateau[x][y] = SPACE; break;
                case '.': plateau[x][y] = BONUS; break; 
                case 'o': plateau[x][y] = OBS; break;
                case 'E': plateau[x][y] = PORTEEAU; break;
                case 'F': plateau[x][y] = PORTEFEU; break;

			}
		}
    
    //placer les bonus dans le plateau
    int nbBonus= (rand () % 7) + 3; //generer entre 3 et 6 bonus
    tabB= new Bonus[dimx][dimy];
    for (int i=0; i<nbBonus; i++)
    {
        
            int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
            int y= (rand ()% dimy);
        do{
            int r =(rand ()% 4 ) + 2; //choisir aléatoirement entre diamantFeu et diamantEau
            switch (r)
                {
                case 2: 
                    tabB[x][y] = Bonus(DiamantEau,x,y);
                    break;
                case 3:
                    tabB[x][y] = Bonus(DiamantFeu,x,y);
                    break;
                default:
                    break;
                }
            
            plateau[x][y] = BONUS;
        }
        while(EstPosValide(x,y) &&  plateau[x][y] != BONUS); //tant que c'est une position valide (pas de mur ni de bloc qui bouge) ET qu'il n'y a pas deja un bonus
    }

    //placer les blocs et les portes dans le plateau
    tabO= new Obstacle[dimx][dimy];
    for (int i=0; i<dimx; i++)
    {
        for (int j=0; j<dimy; j++)
        {
            if (plateau[i][j] == BLOC)
            {
                tabO[i][j]= Obstacle(Bloc,i,j); //les positions des obstacles et bonus servent-ils vrmt à quelque chose?
            }
            if (plateau[i][j] == PORTEEAU)
            {
                tabO[i][j]= Obstacle(PorteE,i,j); //les positions des obstacles et bonus servent-ils vrmt à quelque chose?
            }
            if (plateau[i][j] == PORTEFEU)
            {
                tabO[i][j]= Obstacle(PorteF,i,j); //les positions des obstacles et bonus servent-ils vrmt à quelque chose?
            }
        }
    }

    //placer les obstacles dans le plateau
    int nbObs= (rand () % 8) + 4; 
    for (int i=0; i<nbObs; i++)
    {
        int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
        int y= (rand ()% dimy);
        do{
            
            int r= (rand ()% 7) + 4;         
            switch (r)
                {
                case 4: 
                    tabO[x][y]= Obstacle(Lava,x,y);
                    break;
                case 5:
                    tabO[x][y]= Obstacle(Riviere,x,y);
                    break;
                case 6:
                    tabO[x][y]= Obstacle(O_Vert,x,y);
                    break;
                default:
                    break;
                }
            plateau[x][y]=OBS;
        }
        while(EstPosValide(x,y) ||  plateau[x][y] != OBS)


}
}

Plateau::~Plateau(){
    dimx=0;
    dimy=0;
    if(tabB!= nullptr){ 
        delete [] tabB;
        tabB = nullptr;
    }
    if(tabO!= nullptr){ 
        delete [] tabO;
        tabO = nullptr;
    }
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
        plateau[i][j]= SPACE;
    }
}

int Plateau::getXY(const int x, const int y){
    return plateau[x][y];
}

int Plateau::getDimx()const{
    return dimx;
}

int Plateau::getDimy()const{
    return dimy;
}

CasePlateau Plateau::getPlateau (const int x, const int y){
    return plateau[x][y];
}

Obstacle Plateau:: getObstacle (const int x, const int y){
    return tabO[x][y];
}

Bonus Plateau:: getBonus (const int x, const int y){
    return tabB[x][y];
}

bool Plateau::EstPosValide(const int x, const int y){
    return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (plateau[x][y]!=WALL) && (plateau[x][y]!=BLOC) && (plateau[x][y]!=PORTEFEU) && (plateau[x][y]!=PORTEEAU));
}

void Plateau::mangeBonus(const int x, const int y){
    assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	plateau[x][y]=BONUS;

}