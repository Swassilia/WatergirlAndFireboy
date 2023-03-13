#include "Plateau.h"

const char plateau1[17][21] = {     //le tableau on le voit en format paysage -> rotation à gauche 
    "####################",
    "  p  p             #",
    "################   #",
    "#        ##   ##___#",
    "#      #############",
    "#  ###             #",
    "###    #####       #",
    "#######     ####   #",
    "#               ___#",
    "#    ###############",
    "#___               #",
    "#########          #",
    "#        ######    #",
    "#                  #",
    "#########        ###",
    "#              #####",
    "####################",

    
};

/*const char plateau2[17][21] = {
    "####################",
    "# PE  PF           #",
    "#########    ###   #",
    "#               ___#",
    "#      #############",
    "#  ###             #",
    "###    #######     #",
    "#                ###",
    "#         ###   ####",
    "#   ################",
    "#___               #",
    "####               #",
    "################   #",
    "#                ###",
    "#    ####   #### ###",
    "#                ###",
    "####################",
    
};
*/

Plateau::Plateau(){
    dimx=20;
    dimy=17;
    tabO= nullptr;
    tabB= nullptr;
    for(int x=0;x<dimx;++x)
		for(int y=0;y<dimy;++y)
		{
			switch(plateau1[y][x]) //revoir dans quel ordre sont stockés les éléments
			{
				case '#': plateau[x][y] = WALL; break;
				case '_': plateau[x][y] = BLOC; break; 
				case ' ': plateau[x][y] = SPACE; break;
                case '.': plateau[x][y] = BONUS; break; 
                case 'o': plateau[x][y] = OBS; break;
                case 'p': plateau[x][y] = PORTE; break;
			}
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
void Plateau::setDimx(int x){
    dimx = x;
}
int Plateau::getDimx()const{
    return dimx;
}
void Plateau::setDimy(int y){
    dimy = y;
}
int Plateau::getDimy()const{
    return dimy;
}

void Plateau::EstPosValide(const int x, const int y){
    return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (plateau[x][y]!='#') && (plateau[x][y]!='_'));
}

void Plateau::Placerbonus(){
    Type t;
    int nbBonus= (rand () % 7) + 3; //normalement génére entre 3 et 6 bonus
    tabB= new Bonus[nbBonus];
    for (int i=0; i<nbBonus; i++)
    {
        do{
            unsigned int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
            unsigned int y= (rand ()% dimy);
            tabB = Bonus(t,x,y);
            plateau[x][y]='.'; //correspond au bonus
        }
        while(EstPosValide(x,y) ||  plateau[x][y] != '.') //tant que c'est une position valide (pas de mur ni de bloc qui bouge) ET qu'il n'y a pas deja un bonus
    }

}

void Plateau::PlacerObstacle()
{   Type t;
    plateau[?][?]= Obstacle (Bloc, ?, ?);
    plateau1[?][?]='_';
    plateau[?][?]= Obstacle (Bloc, ?, ?);
    plateau1[?][?]='_';
    plateau[?][?]= Obstacle (Bloc, ?, ?);
    plateau1[?][?]='_';
    plateau[?][?]= Obstacle (PorteE, ?, ?);
    plateau1[?][?]='p';
    plateau[?][?]= Obstacle (PorteF, ?, ?);
    plateau1[?][?]='p';

    int nbObs= (rand () % 8) + 4; //normalement génére entre 4 et 7 obstacles
    for (int i=0; i<nbObs; i++)
    {
        do{
            unsigned int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
            unsigned int y= (rand ()% dimy);
            tabO= Obstacle(t,x,y);
            plateau[x][y]='o';
        }
        while(EstPosValide(x,y) ||  plateau[x][y] != 'o')
    }
}

void Plateau::mangeBonus(){
    assert(x>=0);
	assert(y>=0);
	assert(x<m_dimx);
	assert(y<m_dimy);
	plateau[x][y]=BONUS;

}