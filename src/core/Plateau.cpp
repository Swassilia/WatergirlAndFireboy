#include <cassert>
#include <iostream>
#include "Plateau.h"
#include "Objet.h"
using namespace std;

//construction du labyrinthe via un tableau de char
const char plateau1[19][32] = {
"###############ff##############",
"#                       #######",
"########ee####    ####     ####",
"#   ####      ######        ###",
"#     ##  ###          ##     #",
"#            ##vv##    # ###  #",
"#                   ####      #",
"############                  #",
"########ff#                   #",
"#####          #######__#######",
"#__            ######         #",
"#              ######         #",
"#  ##############ee##   #######",
"#    ##########               #",
"#       ##            ##      #",
"####  #        ######    ######",
"# E        ############     F #",
"#          ############       #",
"###############################",
};

//Constructeur de la classe qui initialise les dimensions avec des entiers définis
//Initialise le tableau plateau avec les NomCase correspondants aux caractères du plateau1
Plateau::Plateau()
{

    dimx=31;
    dimy=19;
    for(int y=0; y<dimy; ++y)
    {
        for(int x=0; x<dimx; ++x)
		{
			switch(plateau1[dimy-1-y][x])
			{                               
				case '#': plateau[x][y] = WALL; break;
				case '_': plateau[x][y] = BLOC; break; 
				case ' ': plateau[x][y] = SPACE; break;
                case '.': plateau[x][y] = BONUS; break; 
                case 'E': plateau[x][y] = PORTEEAU; break;
                case 'F': plateau[x][y] = PORTEFEU; break;
                case 'e': plateau[x][y] = RIVIEREeau; break;
                case 'f': plateau[x][y] = RIVIEREfeu; break;
                case 'v': plateau[x][y] = RIVIEREvert; break;
			}
		}
    }
}

Plateau::~Plateau(){
    dimx=0;
    dimy=0;
    for(int i=0; i<20; i++)
    {
        tabObj[i]= Objet(Defaut,0,0);
    }
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
        plateau[i][j]= SPACE;
    }
}

void Plateau::placerObjet()
{
    //placer les bonus aléatoirement 
    int nb=8;
    int x;
    int y;
    for (int i=0; i<nb; i++)
     {
        do
        {
            x=(rand ()% dimx);
            y=(rand ()% dimy);
        }while (!(EstPosValide(x,y)) || plateau[x][y]!=' ');
        int r=(rand ()% 3) + 1;
        switch (r)
        {
            case 1:
            tabObj[i] = Objet(DiamantEau, x, y);
            break;
            case 2:
            tabObj[i] = Objet(DiamantFeu, x, y);
            break;
            default:
            break;
        }
        plateau[x][y] = BONUS;      
     }
     //placer 5 obstacles rivières
     tabObj[8]=Objet(Lava,18,15);
     tabObj[9]=Objet(Lava,18,16);
     plateau[18][15] = RIVIEREfeu;
     plateau[18][16] = RIVIEREfeu;

     tabObj[10]=Objet(Riviere,16,8);
     tabObj[11]=Objet(Riviere,16,9);
     plateau[16][8] = RIVIEREeau;
     plateau[16][9] = RIVIEREeau;

     tabObj[12]=Objet(O_Vert,13,15);
     tabObj[13]=Objet(O_Vert,13,16);
     plateau[13][15] = RIVIEREvert;
     plateau[13][16] = RIVIEREvert;
    
     tabObj[14]=Objet(Lava,10,8);
     tabObj[15]=Objet(Lava,10,9);
     plateau[10][8] = RIVIEREfeu;
     plateau[10][9] = RIVIEREfeu;

     tabObj[16]=Objet(Riviere,6,17);
     tabObj[17]=Objet(Riviere,6,18);
     plateau[6][17] = RIVIEREeau;
     plateau[6][18] = RIVIEREeau;

     //placer les blocs
     tabObj[18]=Objet(Bloc,8,1);
     tabObj[19]=Objet(Bloc,8,2);
     plateau[8][1] = BLOC ;
     plateau[8][2] = BLOC;

     tabObj[20]=Objet(Bloc,9,22);
     tabObj[21]=Objet(Bloc,9,23);
     plateau[9][22] = BLOC;
     plateau[9][23] = BLOC;

     //placer les portes
     tabObj[22]=Objet(PorteE,2,2);
     plateau[2][2] = PORTEEAU;

     tabObj[23]=Objet(PorteF,2,28);
     plateau[2][28] = PORTEFEU;

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

bool Plateau::EstPosValide(const int x, const int y){
    assert(x>=0 && y>=0);
    assert(x<dimx && y<dimy);
    return (plateau[x][y]!='#');
}

void Plateau::mangeBonus(const int x, const int y){
    assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	plateau[x][y]=BONUS;

}

void Plateau::testRegression_Pla(){
    Plateau pla;
}