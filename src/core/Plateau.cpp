
#include <cassert>
#include <iostream>
#include "Plateau.h"
#include "Objet.h"
using namespace std;

//construction du labyrinthe via un tableau de char
  const char plateau1[23][33] = {
  "################################",
  "################ff##############",
  "##        r              #######",
  "##      ####                  ##",
  "#########ee####    ####     ####",
  "##   ####      ######        ###",
  "##     ##  ###          ##     #",
  "##     b      ##vv##    #####  #",
  "##                   ####      #",
  "#############                  #",
  "########ee#                    #",
  "######          ######__ #######",
  "#__             ######         #",
  "#              ######     ######",
  "#  ##############ee##   ###ff###",
  "#    ##########               ##",
  "#       ##            ##      ##",
  "##                            ##",
  "#####          ######    #######",
  "# E        ###########      F ##",
  "#                             ##",
  "################################",
  "################################",
  };

//Constructeur de la classe qui initialise les dimensions avec des entiers définis
//Initialise le tableau plateau avec les NomCase correspondants aux caractères du plateau1
Plateau::Plateau()
{

    dimx=33;
    dimy=23;
  
    int i=0;
    for(int y=0; y<dimy; ++y)
    {
        for(int x=0; x<dimx; ++x)
		{
			switch(plateau1[dimy-1-y][x])
			{                               
				case '#': 
                plateau[x][y] = WALL;
                break; 

				case ' ': 
                plateau[x][y] = SPACE; 
                break;

                case '_': 
                plateau[x][y] = BLOC;
                tabObj[i]=Objet(Bloc,x,y);
                i++;
                break;

                case 'r': 
                plateau[x][y] = BONUSFEU;
                tabObj[i]=Objet(DiamantFeu,x,y);
                i++;
                break;

                case 'b': 
                plateau[x][y] = BONUSEAU;
                tabObj[i]=Objet(DiamantEau,x,y);
                i++;
                break; 

                case 'E': 
                plateau[x][y] = PORTEEAU;
                tabObj[i]=Objet(PorteE,x,y);  
                i++;
                break;

                case 'F': 
                plateau[x][y] = PORTEFEU;
                tabObj[i]=Objet(PorteF,x,y);
                i++;
                break;

                case 'e': 
                plateau[x][y] = RIVIEREeau;
                tabObj[i]=Objet(Riviere,x,y);
                i++;
                break;

                case 'f': 
                plateau[x][y] = RIVIEREfeu;
                tabObj[i]=Objet(Lava,x,y);
                i++;
                break;
                
                case 'v': 
                plateau[x][y] = RIVIEREvert;
                tabObj[i]=Objet(O_Vert,x,y);
                i++;
                break;
			}
		}
    }
}

Plateau::~Plateau(){
    dimx=0;
    dimy=0;
    for(int i=0; i<30; i++)
    {
        tabObj[i]= Objet(Defaut,0,0);
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
void Plateau:: setPlateau(const Vect2& v, const NomCase &n)
{
    plateau[v.x][v.y]=n;
}
NomCase Plateau::getPlateau (const int x, const int y) const{
    assert(x>=0 && y>=0);
    assert(x<dimx && y<dimy);
    return plateau[x][y];
}

Objet Plateau:: getObjet (const int x){
    assert(x>=0);
    assert(x<30);
    return tabObj[x];
}

bool Plateau::EstPosValide(const int x, const int y)const{

    return ((x>=0) && (x<dimx) &&(y>=0) && (y<dimy) && plateau[x][y]!='#' && plateau[x][y]!='_');
}

void Plateau::bougeAuto(){
 
    int blocCounter = 4;

    // Parcours du tableau pour trouver l'objet de type Bloc et le déplacer en dessous si la case est vide
    for(int i = 0; i < 30; i++){
        if(tabObj[i].getType() == Bloc){
            int x = tabObj[i].getPos().x;
            int y = tabObj[i].getPos().y;
            cout<<x<<endl;
            // Si la case en dessous est vide, déplacer le bloc
            if(x - 1 <= dimy){
                setPlateau(make_Vect2(x,y-1),BLOC);
                plateau[x][y] = SPACE;
                tabObj[i].setPos(x, y-1);
                assert(x<dimx);
                assert(y<dimy);
                cout<<x<<" "<<y<<endl;
            }
            //break;
            
        }
    }
}
//&& plateau1[x + 1][y] == SPACE

