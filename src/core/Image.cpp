#include "Image.h"
#include "Pixel.h"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

//Constructeur par défaut de la classe: initialise dimx et dimy à 0 
//ce constructeur n'alloue pas de pixel
Image::Image()
{
    dimx=0;
    dimy=0;
    tab=nullptr;

}

//Constructeur de la classe: initialise dimx et dimy (après vérification)
//puis alloue le tableau de pixel dans le tas (image noire)
Image::Image(const unsigned int &dimensionX, const unsigned int &dimensionY)
{
    assert(dimensionX>0 && dimensionY>0);
    dimx=dimensionX;
    dimy=dimensionY;

    tab = new Pixel[dimx*dimy];
}
//Destructeur 
Image:: ~Image()
{
   
    dimx=0;
    dimy=0;

    if(tab!= nullptr){
        delete [] tab;
        tab = nullptr;
    }

}

//Accesseur: récupère le pixel original de coordonnées (x,y)
Pixel & Image:: getPix (const unsigned int x,const unsigned int y)const{
    assert( x>=0 && y>=0);
    assert( x<dimx && y<dimy );
    return tab[y*dimx+x];
}
//Mutateur : modifie le pixel de coordonnées (x,y)
void Image::setPix(const unsigned int x, const unsigned int y, const Pixel &couleur)const{
    assert(x>=0 && y>=0);
    assert (x<dimx && y<dimy);
    assert(tab!= nullptr);
    // tab[y*dimx+x] = couleur;
    tab[y*dimx+x].setRouge(couleur.getRouge());
    tab[y*dimx+x].setVert(couleur.getVert());
    tab[y*dimx+x].setBleu(couleur.getBleu());
    

}
//Efface l'image en la remplissant de la couleur en paramètre
void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin,unsigned int Xmax, unsigned int Ymax, const Pixel& couleur)
{
    assert(Xmin>=0);// les valeurs accepté pour Xmin €[0, Xmax]
    assert(Ymin>=0); // les valeurs accepté pour Ymin €[0, Ymax]
    assert(Xmin<dimx);
    assert(Xmax<dimx);// les valeurs accepté pour Xmax €]Xmin, dimx]
    //assert(Ymin<dimy);
    //assert(Ymax<dimy);// les valeurs accepté pour Ymax €]Ymin, dimy]
    //assert(Ymin<Ymax);
    //assert(Xmin<Xmax);
    for (unsigned int j=Ymin; j<=Ymax;j++ )
    {
        for (unsigned int i=Xmin; i<=Xmax;i++ )
        {
            setPix(i,j,couleur);
        }  
    }
}
//Affiche dans la console les valeurs des pixels 
void Image::effacer(const Pixel & couleur)
{
    dessinerRectangle (0,0,dimx-1,dimy-1,couleur);
}
//On test chaque cas 
void Image::testRegression()const{
    Image im1(100,100);
    Image im2;
    Pixel rouge(255,0,0);
    Pixel bleu(0,0,255);
    Pixel vert(0,255,0);

    Pixel noir(0,0,0);
    
    //constructeur
    assert(im2.dimx == 0);
    assert(im2.dimy == 0);
    assert(im2.tab == nullptr);

    assert(im1.dimx == 100);
    assert(im1.dimy == 100);
    assert(im1.tab == &im1.tab[0]);

    //setPix
    im1.setPix(99,99,rouge); //x et y doivent bien etre different à dimx et dimy
    im1.setPix(88,99,bleu);
    im1.setPix(63,45,vert);
    
    //getPix
    im1.getPix(99,99);

    //dessiner Rectangle
    im1.dessinerRectangle(10,10,20,20,rouge);

    //afin de bien s'assurer que la fonction fonctionne comme il faut on pose des assertions qui verifient que la couleur rouge est bien utilisée
    //dans les dimentions données
    for (unsigned int x=10; x<20; x++){
        for(unsigned int y=10; y<20; y++){
            assert(im1.getPix(x,y).getVert()== rouge.getVert());
            assert(im1.getPix(x,y).getVert()== rouge.getVert());
            assert(im1.getPix(x,y).getVert()== rouge.getVert());
        }
    }

    //effacer
    im1.effacer(noir);

    //afin de bien s'assurer que la fonction fonctionne comme il faut on pose des assertions qui verifient que l'écran prend la couleur noir
    //dans les dimentions données
    for (unsigned int x=10; x<20; x++){
        for(unsigned int y=10; y<20; y++){
            assert(im1.getPix(x,y).getVert()== noir.getVert());
            assert(im1.getPix(x,y).getVert()== noir.getVert());
            assert(im1.getPix(x,y).getVert()== noir.getVert());
        }
    }
 

}
//Sauvegarde l'image dans un fichier 
void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str()); //ecrire
    assert(fichier.is_open());// on teste si le fichier est deja ouvert
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)//la boucle sauvergarde Pixel par Pixeldans le fichier 
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel &pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}
//Ouvre le fichier 
void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());// on teste si le fichier est deja ouvert
	unsigned char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);// on teste l'intervalle
	if (tab != NULL) delete [] tab;//Si tab pointe sur quelque chose on l'a supprime
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)// On affiche Pixel par Pixel
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> g >> b;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}
//On affiche dans la console les valeur de chaque Pixel
void Image::afficherConsole()const{
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}







