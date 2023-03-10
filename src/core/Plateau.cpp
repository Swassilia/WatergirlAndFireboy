#include "Plateau.h"

const char plateau1[17][20] = {
    "####################"
    "  PE  PF           #"
    "################   #"
    "#        ##   ##___#"
    "#      #############"
    "#  ###             #"
    "###    #####       #"
    "#######     ####   #"
    "#               ___#"
    "#    ###############"
    "#___               #"
    "#########          #"
    "#        ######    #"
    "#                  #"
    "#########        ###"
    "#              #####"
    "####################"
    
}
const char plateau2[17][20] = {
    "####################"
    "# PE  PF           #"
    "#########    ###   #"
    "#               ___#"
    "#      #############"
    "#  ###             #"
    "###    #######     #"
    "#                ###"
    "#         ###   ####"
    "#   ################"
    "#___               #"
    "####               #"
    "################   #"
    "#                ###"
    "#    ####   #### ###"
    "#                ###"
    "####################"
    
}
Plateau::Plateau(){
    dimx=17;
    dimy=20;
    tabO= nullptr;
    tabB= nullptr;

    for(int x=0;x<dimx;++x)
		for(int y=0;y<dimy;++y)
		{
			switch(plateau1[dimy-1-y][x]) //l'inverse plus tot non?
			{
				case '#': plateau1[x][y] = WALL; break;
				case '_': plateau1[x][y] = BLOC; break; //pas des obstacles plus tot :oui mais ils ont une place precise dans chaque plateau
				case ' ': plateau1[x][y] = SPACE; break;
                //case '.': plateau1[x][y] = DOT;break; //on a pas de dot pas besoin non :c'est les diamonts mais jenleve vu quon les placera plus tard
			}
		}
    for(int x=0;x<dimx;++x)
		for(int y=0;y<dimy;++y)
		{
			switch(plateau2[dimy-1-y][x])
			{
				case '#': plateau2[x][y] = WALL; break;
				case '_': plateau2[x][y] = BLOC; break;
				case ' ': plateau2[x][y] = SPACE; break;
                //case '.': plateau2[x][y] = DOT;break;
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
}

int Plateau::getXY(){

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

void Plateau::Placerbonus(){
    for(int i=0;i<dimx;i++)
        for(int j=0;j<dimy;j++){
            
                tabB[i][j];       
            
        }
}
/*idée pour faciliter les tirage au sort
int random(int low, int high)
{
    return low + rand() % (high - low + 1);
}

donc si on veut tirer un nombre entre 5 et 10: random (5,10);
*/

/*void Plateau::Placerbonus(){
    int nbBonus= (rand () % 3) + 3; //normalement génére entre 3 et 6 bonus
    tabB= new Bonus[nbBonus];
    for (int i=0; i<nbBonus; i++)
    {
        do{
            unsigned int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
            unsigned int y= (rand ()% dimy);
            tabB = Bonus(x,y);
        }
        while(plateau1[x][y] != WALL || tabB[x][y] != "deja pris") //comment traduire le "deja pris"
    }

}*/

void Plateau::PlacerObstacle()
{
    int nbObs= (rand () % 4) + 4; //normalement génére entre 4 et 7 obstacles
    for (int i=0; i<nbObs; i++)
    {
        do{
            unsigned int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
            unsigned int y= (rand ()% dimy);
            tabO= Obstacle(x,y);
        }
        while(plateau1[x][y] != WALL || tabO[x][y] != "deja pris") //comment traduire le "deja pris"
    }
}

void Plateau::EstPosValide(const int x, const int y){
    return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (plateau1[x][y]!='#'));
}
void Plateau::mangeBonus(){
    assert(x>=0);
	assert(y>=0);
	assert(x<m_dimx);
	assert(y<m_dimy);
	plateau1[x][y]=DOT;

}
void Plateau::AjoutBonus(){//il ya une fonction qui fait la meme chose dans la classe Jeu qui ajoute +1 au score si on fait une collision avec Bonus

}

int Plateau::tempEcoule(){//je pense la mettre dans la classe Jeu directement au lieu de plateau c mieux nn?


}