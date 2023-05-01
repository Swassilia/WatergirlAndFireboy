#include <cassert>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Plateau.h"
#include "Objet.h"
using namespace std;

//construction du labyrinthe via un tableau de char
 const char plateau1[23][33] = {
  "################################",
  "################ff##############",
  "##                       #######",
  "##      ####                  ##",
  "#########ee####    ####     ####",
  "##   ####      ##v###        ###",
  "##     ##  ###          ##     #",
  "##            ### ##    ####   #",
  "##                   ####      #",
  "#############                  #",
  "########e##                    #",
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

//tableau qui permet de tester toutes les collisions 
 /*const char plateauessai[23][33] = {
  "################################",
  "################ff##############",
  "##                 F     #######",
  "##      ####             E     ##",
  "#########ee####    ####     ####",
  "##   ####      ######        ###",
  "##     ##  ###          ##     #",
  "##            ##vv##    #####  #",
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
  "#          ###########       ##",
  "#                             ##",
  "################################",
  "################################",
  };*/

//Constructeur de la classe qui initialise les dimensions avec des entiers définis
//Initialise le tableau plateau avec les NomCase correspondants aux caractères du plateau1
Plateau::Plateau()
{

    dimx=33;
    dimy=23;
  
    int i=0;
    int j=0;
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
                tabBloc[j]=Objet(Bloc,x,y);
                j++;
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
        
    //Placement des bonus EAU
    plateau[6][15] = BONUSEAU;
    tabObj[i]=Objet(DiamantEau,6,15);
    i++;
    plateau[29][16] = BONUSEAU;
    tabObj[i]=Objet(DiamantEau,29,16);
    i++;
    plateau[24][5] = BONUSEAU;
    tabObj[i]=Objet(DiamantEau,24,5);
    i++;
    //Placement des bonus Feu 
    plateau[17][20] = BONUSFEU;
    tabObj[i]=Objet(DiamantFeu,17,20);
    i++;
    plateau[9][4] = BONUSFEU;
    tabObj[i]=Objet(DiamantFeu,9,4);
    i++;
    plateau[27][7] = BONUSFEU;
    tabObj[i]=Objet(DiamantFeu,27,7);
    i++;

    
}

//Destructeur du plateau
Plateau::~Plateau(){
    dimx=0;
    dimy=0;
    for(int i=0; i<30; i++)
    {
        tabObj[i]= Objet(Defaut,0,0);
    }
    for(int i=0; i<4; i++)
    {
        tabBloc[i]= Objet(Defaut,0,0);
    }
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
        plateau[i][j]= SPACE;
    }
}

//Accesseur : récupère la dimension en x du plateau
int Plateau::getDimx()const{
    return dimx;
}

//Accesseur : récupère la dimension en y du plateau
int Plateau::getDimy()const{
    return dimy;
}

//Mutateur : redéfinit un objet dans le tableau d'objet
void Plateau:: setObjet(int i, const Type &t)
{
    tabObj[i]=Objet(t,tabObj[i].getPos().x,tabObj[i].getPos().y);
}

//Mutateur : redéfinit une case du plateau
void Plateau:: setPlateau(const Vect2 &v,const NomCase &n)
{
    plateau[v.x][v.y]=n;
}

//Accesseur : recupere la case du plateau dans les coordonnees x et y
//pour savoir ce qu'il y a dedans
NomCase Plateau::getPlateau (const int x, const int y) const{
    assert(x>=0 && y>=0);
    assert(x<dimx && y<dimy);
    return plateau[x][y];
}

//Accesseur : recupere l'objet dans le tableau d'objet
Objet Plateau:: getObjet (const int x){
    assert(x>=0);
    assert(x<30);
    return tabObj[x];
}

//verifier si une position est valide (libre) dans le plateau aux coordonees x et y
bool Plateau::EstPosValide(const int x, const int y)const{

    return ((x>=0) && (x<dimx) &&(y>=0) && (y<dimy) && plateau[x][y]!='#' && plateau[x][y]!='_');
}

//permet de bouger les blocs dans le plateau
void Plateau::bougeAuto(){
 
    // Parcours du tableau pour trouver l'objet de type Bloc et le déplacer en dessous si la case est vide
        for(int i = 0; i < 2; i++){
        
            int x = tabBloc[i].getPos().x;
            int y = tabBloc[i].getPos().y;
            vitesse  = 1;

            //printf("X : %d   Y : %d ", x, y);
            if(y - 1 >= 7 ){
                setPlateau(make_Vect2(x,y-vitesse),BLOC);
                plateau[x][y] = SPACE;
                tabBloc[i].setPos(x, y-vitesse);
                assert(x<dimx);
                assert(y<dimy);
            }else
            setPlateau(make_Vect2(x,y+3),BLOC);
            plateau[x][y] = SPACE;
        
        for(int i = 2; i < 4; i++){
        
            int x = tabBloc[i].getPos().x;
            int y = tabBloc[i].getPos().y;
            vitesse  = 1;

            //printf("X : %d   Y : %d ", x, y);
            if(y - 1 >= 8 ){
                setPlateau(make_Vect2(x,y-vitesse),BLOC);
                plateau[x][y] = SPACE;
                tabBloc[i].setPos(x, y-vitesse);
                assert(x<dimx);
                assert(y<dimy);
            }else 
            setPlateau(make_Vect2(x,y+3),BLOC);
            plateau[x][y] = SPACE;
        }
    }
}


