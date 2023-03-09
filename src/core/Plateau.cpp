#include "Plateau.h"

const char plateau1[17][20] = {
    "####################"
    "  PE  PF            "
    "################    "
    "#        ##   ##____"
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
    "  PE  PF            "
    "#########    ###    "
    "#               ____"
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
			switch(plateau1[dimy-1-y][x])
			{
				case '#': plateau1[x][y] = WALL; break;
				case '_': plateau1[x][y] = BLOC; break;
				case ' ': plateau1[x][y] = SPACE; break;
                case '.': plateau1[x][y] = DOT;break;
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
                case '.': plateau2[x][y] = DOT;break;
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