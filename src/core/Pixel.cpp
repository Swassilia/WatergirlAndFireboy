#include "Pixel.h"

// constructeur par default Pixel noir
Pixel::Pixel(){
    r=0;
    g=0;
    b=0;
}

//constructeur initialise r,g,b avec les paramètres
Pixel::Pixel(unsigned char nr,unsigned char ng,unsigned char nb) {
    r=nr;
    g=ng;
    b=nb;
}
//Accesseur : récupère la composante rouge du pixel
unsigned char Pixel::getRouge() const
{
    return r;
}

//Accesseur : récupère la composante vert du pixel
unsigned char  Pixel::getVert() const 
{
    return g;
}

//Accesseur : récupère la composante bleu du pixel
unsigned char  Pixel::getBleu() const
{
    return b;
}

// Mutateur : modifie la composante rouge du pixel
void Pixel::setRouge(unsigned char nr){
    r = nr;
}

 //Mutateur : modifie la composante vert du pixel
void Pixel::setVert(unsigned char ng){
    g = ng;
}

// Mutateur : modifie la composante bleu du pixel
void Pixel::setBleu(unsigned char nb){
    b = nb;
}

