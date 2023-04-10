#include <cassert>
#include <iostream>
#include "Plateau.h"
#include "Objet.h"
using namespace std;

//construction du labyrinthe via un tableau de char
const char plateau1[23][32] = {
"###############################",
"###############ff##############",
"#                       #######",
"#              b             ##",
"########ee####    ####     ####",
"#   ####      ######        ###",
"#     ##  ###          ##     #",
"#     r      ##vv##    #b###  #",
"#                   ####      #",
"############                  #",
"#######ff#                    #",
"#####          #######__#######",
"#__            ######       f #",
"#              ######         #",
"#  ##############ee##   #######",
"#    ##########             f #",
"#       ##            ##      #",
"##       b                    #",
"#####          ######    ######",
"# E        ###########      F #",
"#          ############       #",
"###############################",
};

//Constructeur de la classe qui initialise les dimensions avec des entiers définis
//Initialise le tableau plateau avec les NomCase correspondants aux caractères du plateau1
Plateau::Plateau()
{

    dimx=32;
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

				case '_': 
                plateau[x][y] = BLOC;
                tabObj[i]=Objet(Bloc,x,y);
                i++;
                break; 

				case ' ': 
                plateau[x][y] = SPACE; 
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
    assert(x>=0 && y>=0);
    assert(x<dimx && y<dimy);
    return (plateau[x][y]!='#');
}

// void Plateau::mangeBonus(const int x, const int y){
//     assert(x>=0);
// 	assert(y>=0);
// 	assert(x<dimx);
// 	assert(y<dimy);
// 	plateau1[x][y]=BONUSEAU;
//     plateau1[x][y]=BONUSFEU;

// }

void Plateau::testRegression_Pla(){
    Plateau pla;
}
