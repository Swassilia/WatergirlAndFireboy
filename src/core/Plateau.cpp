
#include <cassert>
#include <iostream>
#include "Plateau.h"
using namespace std;

const char plateau1[15][32] = {
    "###############################", 
    "#  p       ########        p  #",
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
    for(unsigned int x=0;x<dimx;++x)
		for(unsigned int y=0;y<dimy;++y)
		{
			switch(plateau1[dimy-1-y][x]) //revoir dans quel ordre sont stockés les éléments
			{
				case '#': plateau[x][y] = WALL; break;
               std::cout<< x << y <<' '<<plateau[x][y]<<std::endl;
				case '_': plateau[x][y] = BLOC; break; 
				case ' ': plateau[x][y] = SPACE; break;
                case '.': plateau[x][y] = BONUS; break; 
                case 'o': plateau[x][y] = OBS; break;
                case 'p': plateau[x][y] = PORTE; break;
			}
		}
}

// Plateau::~Plateau(){
//     dimx=0;
//     dimy=0;
//     if(tabB!= nullptr){ 
//         delete [] tabB;
//         tabB = nullptr;
//     }
//     if(tabO!= nullptr){ 
//         delete [] tabO;
//         tabO = nullptr;
//     }
//     for(int i=0; i<50; i++)
//     {
//         for(int j=0; j<50; j++)
//         plateau[i][j]= SPACE;
//     }
// }

// int Plateau::getXY(const int x, const int y){
//     return plateau[x][y];
// }
// void Plateau::setDimx(int x){
//     dimx = x;
// }
// int Plateau::getDimx()const{
//     return dimx;
// }
// void Plateau::setDimy(int y){
//     dimy = y;
// }
// int Plateau::getDimy()const{
//     return dimy;
// }

// bool Plateau::EstPosValide(const int x, const int y){
//     return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (plateau[x][y]!='#') && (plateau[x][y]!='_'));
// }

// void Plateau::PlacerBonus(){
//     Type t;
//     int nbBonus= (rand () % 7) + 3; //genrer entre 3 et 6 bonus
//     tabB= new Bonus[nbBonus];
//     for (int i=0; i<nbBonus; i++)
//     {
        
//             unsigned int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
//             unsigned int y= (rand ()% dimy);
//         do{
//             int i =(rand ()% 4 ) + 2;
//             switch (i)
//                 {
//                 case 2: 
//                     tabB[i] = Bonus(DiamantEau,x,y);
//                     break;
//                 case 3:
//                     tabB[i] = Bonus(DiamantFeu,x,y);
//                     break;
//                 default:
//                     break;
//                 }
            
//             plateau[x][y] = BONUS;
//         }
//         while(EstPosValide(x,y) &&  plateau[x][y] != BONUS); //tant que c'est une position valide (pas de mur ni de bloc qui bouge) ET qu'il n'y a pas deja un bonus
//     }

// }

// void Plateau::PlacerObstacle()
// {   Type t;
//     plateau[?][?]= Obstacle (Bloc, ?, ?);
//     plateau1[?][?]='_';
//     plateau[?][?]= Obstacle (Bloc, ?, ?);
//     plateau1[?][?]='_';
//     plateau[?][?]= Obstacle (Bloc, ?, ?);
//     plateau1[?][?]='_';
//     plateau[?][?]= Obstacle (PorteE, ?, ?);
//     plateau1[?][?]='p';
//     plateau[?][?]= Obstacle (PorteF, ?, ?);
//     plateau1[?][?]='p';

//     int nbObs= (rand () % 8) + 4; 
//     for (int i=0; i<nbObs; i++)
//     {
//         unsigned int x= (rand ()% dimx); //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
//         unsigned int y= (rand ()% dimy);
//         do{
            
//             int i= (rand ()% 7) + 4;         
//             switch (i)
//                 {
//                 case 4: 
//                     tabO[i]= Obstacle(Lava,x,y);
//                     break;
//                 case 5:
//                     tabO[i]= Obstacle(Riviere,x,y);
//                     break;
//                 case 6:
//                     tabO[i]= Obstacle(O_Vert,x,y);
//                     break;
//                 default:
//                     break;
//                 }
//             plateau[x][y]=OBS;
//         }
//         while(EstPosValide(x,y) ||  plateau[x][y] != OBS)
//     }
// }

// void Plateau::mangeBonus(const int x, const int y){
//     assert(x>=0);
// 	assert(y>=0);
// 	assert(x<dimx);
// 	assert(y<dimy);
// 	plateau[x][y]=BONUS;

// }