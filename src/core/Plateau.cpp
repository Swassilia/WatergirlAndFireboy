#include <cassert>
#include <iostream>
#include "Plateau.h"
using namespace std;

//construction du labyrinthe via un tableau de char
const char plateau1[15][32] = {
    "###############ff##############",
    "#                       #######", 
    "######eee#####    #####    ####",
    "#   #         ######        ###",
    "#   ##  ####        ###########",
    "#            ##vv##           #",
    "######ff####        ###########",
    "#__           ###### __########",
    "#             ######          #",
    "#  #############ee##   ########",
    "#    #########                #",
    "#       ##          ###       #",
    "#######    ##########    ######",
    "#  E       ########        F  #",
    "###############################", 
};

//Constructeur de la classe qui initialise les dimensions avec des entiers définis
//Initialise le tableau plateau avec les NomCase correspondants aux caractères du plateau1
//Initalise le tableau de Bonus avec les mêmes dimensions que plateau pour pouvoir placer des bonus à des position valides (estposvalide)
//Place les obstacles de types Bloc et Porte dans le tableau d'obstacle à des positions deja definies dans le plateau (fait correspondre '_' à Obstacle type bloc etc )
//Initialise le tableau d'obstacle avec les mêmes dimensions que plateau pour pouvoir placer des obstacles à des positions valides 
Plateau::Plateau()
{

    dimx=31;
    dimy=15;
    for(int y=0; y<dimy; ++y)
    {
        for(int x=0; x<dimx; ++x)
		{
			switch(plateau1[dimy-1-y][x])   //par rapport au caractere stocke dans la case de plateau1,
			{                               //plateau recupere un nom de case
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
    /*if(tabB!= nullptr){ 
        delete [] tabB;
        tabB = nullptr;
    }*/
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
    for (int i=0; i<nb; i++)
     {
         int x;
         int y;
         do
         {       
             x=(rand ()% dimx);
             y= (rand ()% dimy);                    
             switch (r)
             {
                 case 2: 
                     tabObj[i] = Objet(DiamantEau,x,y);
                     break;
                 case 3:
                     tabObj[i] = Objet(DiamantFeu,x,y);
                     break;
                 default:
                     break;
             }
             plateau[x][y] = BONUS;      
         }
         while(EstPosValide(x,y) &&  plateau[x][y] != '.'); //ou plateau[x][y]!= BONUS.
     }
     //placer 5 obstacles rivières
     tabObj[8]=Objet(Lava,14,13);
     tabObj[9]=Objet(Lava,14,14);
     plateau[14][13] = RIVIEREfeu;
     plateau[14][14] = RIVIEREfeu;

     tabObj[10]=Objet(Riviere,12,5);
     tabObj[11]=Objet(Riviere,12,6);
     tabObj[12]=Objet(Riviere,12,7);
     plateau[12][5] = RIVIEREeau;
     plateau[12][6] = RIVIEREeau;
     plateau[12][7] = RIVIEREeau;

     tabObj[13]=Objet(O_Vert,7,13);
     tabObj[14]=Objet(O_Vert,7,14);
     plateau[7][13] = RIVIEREvert;
     plateau[7][14] = RIVIEREvert;
    
     tabObj[15]=Objet(Lava,6,5);
     tabObj[16]=Objet(Lava,6,6);
     plateau[6][5] = RIVIEREfeu;
     plateau[6][6] = RIVIEREfeu;

     tabObj[17]=Objet(Riviere,12,6);
     tabObj[18]=Objet(Riviere,12,7);
     plateau[1][5] = RIVIEREeau;
     plateau[12][6] = RIVIEREeau;

}
/*void Plateau::placerBonus()
{
    //placer les bonus dans le plateau
    int nb= (rand () % 8) + 4;     
    //tabB= new Bonus[dimx*dimy];        //allocation d'un tableau dynamique
    for (int i=0; i<nb; i++)
     {
         int x;    //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
         int y;
         do
         {       
             x=(rand ()% dimx);
             y= (rand ()% dimy);                     //le but étant de placer les bonus aleatoirement tant que la case du plateau correspondant n'est pas deja prise
             int r =(rand () % 4 ) + 2;   //choisir aléatoirement entre diamantFeu et diamantEau
             switch (r)
             {
                 case 2: 
                     tabB[y*dimx+x] = Bonus(DiamantEau,x,y);q
                     break;
                 case 3:
                     tabB[y*dimx+x] = Bonus(DiamantFeu,x,y);
                     break;
                 default:
                     break;
             }
             plateau[x][y] = BONUS;      //preciser que maintenant dans plateau, aux coordonnee x et y, il y a un Bonus
         }
         while(EstPosValide(x,y) &&  plateau[x][y] != '.');     //tant que c'est une position valide (pas de mur ni de bloc qui bouge) ET qu'il n'y a pas deja un bonus
     }

    //placer les blocs et les portes dans le tableau obstacle (pour definir leur positionnement)
    //tabO= new Obstacle[dimx][dimy];     //allocation d'un tableau dynamique
}
*/

/*void Plateau::placerObstacle()
{
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
         int x;     //generer une coordonnee x compris entre 0 et dimx (dimension du tableau)
         int y;
         do{
             x= (rand ()% dimx);
             y= (rand ()% dimy);
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
*/
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

/*Bonus Plateau:: getBonus (const int x, const int y){
    assert(x>=0 && y>=0);
    assert(x<dimx && y<dimy);
    return tabB[y*dimx+x];
}*/

bool Plateau::EstPosValide(const int x, const int y){
    assert(x>=0 && y>=0);
    assert(x<dimx && y<dimy);
    return ((plateau[x][y]!='#') && (plateau[x][y]!='_') && 
        (plateau[x][y]!='E') && (plateau[x][y]!='F'));
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