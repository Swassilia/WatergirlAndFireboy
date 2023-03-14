#include <cassert>
#include <iostream>
#include "Plateau.h"
using namespace std;

//construction du labyrinthe via un tableau de char
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

//Constructeur de la classe qui initialise les dimensions avec des entiers définis
//Initialise le tableau plateau avec les NomCase correspondants aux caractères du plateau1
//Initalise le tableau de Bonus avec les mêmes dimensions que plateau pour pouvoir placer des bonus à des position valides (estposvalide)
//Place les obstacles de types Bloc et Porte dans le tableau d'obstacle à des positions deja definies dans le plateau (fait correspondre '_' à Obstacle type bloc etc )
//Initialise le tableau d'obstacle avec les mêmes dimensions que plateau pour pouvoir placer des obstacles à des positions valides 
Plateau::Plateau(){
    dimx=31;
    dimy=15;
    for(int y=0;y<dimy;++y)
        for(int x=0;x<dimx;++x)
		{
			switch(plateau1[dimy-1-y][x])   //par rapport au caractere stocke dans la case de plateau1,
			{                               //plateau recupere un nom de case
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
    int nbBonus= (rand () % 7) + 3;     //generer entre 3 et 6 bonus
    tabB= new Bonus[31][15];        //allocation d'un tableau dynamique
    for (int i=0; i<nbBonus; i++)
    {
        
            int x= (rand ()% dimx);     //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
            int y= (rand ()% dimy);
        do{                             //le but étant de placer les bonus aleatoirement tant que la case du plateau correspondant n'est pas deja prise
            int r =(rand ()% 4 ) + 2;   //choisir aléatoirement entre diamantFeu et diamantEau
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
            
            plateau[x][y] = BONUS;      //preciser que maintenant dans plateau, aux coordonnee x et y, il y a un Bonus
        }
        while(EstPosValide(x,y) &&  plateau[x][y] != BONUS);     //tant que c'est une position valide (pas de mur ni de bloc qui bouge) ET qu'il n'y a pas deja un bonus
    }

    //placer les blocs et les portes dans le tableau obstacle (pour definir leur positionnement)
    tabO= new Obstacle[dimx][dimy];     //allocation d'un tableau dynamique
    for (int i=0; i<dimx; i++)
    {
        for (int j=0; j<dimy; j++)
        {
            if (plateau[i][j] == BLOC)     //on detecte l'emplacement dans plateau des portes et des blocs en mouvement pour pouvoir les stocke aux mêmes endroits dans le tableau obstacle
            {
                tabO[i][j]= Obstacle(Bloc,i,j); //les positions des obstacles et bonus servent-ils vrmt à quelque chose?
            }
            if (plateau[i][j] == PORTEEAU)
            {
                tabO[i][j]= Obstacle(PorteE,i,j); 
            }
            if (plateau[i][j] == PORTEFEU)
            {
                tabO[i][j]= Obstacle(PorteF,i,j); 
            }
        }
    }
    
    //placer les autres obstacles dans le tableau obstacle
    int nbObs= (rand () % 8) + 4; 
    for (int i=0; i<nbObs; i++)
    {
        int x= (rand ()% dimx);     //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
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
        while(EstPosValide(x,y) ||  plateau[x][y] != OBS);
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

int Plateau::getDimx()const{
    return dimx;
}

int Plateau::getDimy()const{
    return dimy;
}

NomCase Plateau::getPlateau (const int x, const int y) const{
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