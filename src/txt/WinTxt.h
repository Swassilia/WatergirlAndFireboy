/**
@brief Module qui définit une classe pour gérer l'affichage en mode texte du jeu
@file WinTxt.h
@date 2023/03/14
*/
#ifndef WINTXT_H
#define WINTXT_H

/**
 * @brief représenter une fenêtre texte en mode console
*/
class WinTXT
{

private:

    int dimx;       
    int dimy;       
    char* win;      

public:

    /**
    * @brief constructeur qui initialise une fenêtre texte
    * 
    * @param dx int largeur
    * @param dy int longueur
    */
    WinTXT (int dx, int dy);

    /**
     * @brief remplit la fenêtre avec le caractère spécifié, qui par défaut est un espace
    */
    void clear (char c=' ');

    /**
     * @brief place un caractère à une position dans la fenêtre
     * 
     * @param x int coordonée en x
     * @param y int coordonnée en y
     * @param c char à placer
    */
    void print (int x, int y, char c);

    /**
     * @brief place la chaîne de caractères à une position dans la fenêtre
     * 
     * @param x int coordonée en x
     * @param y int coordonnée en y
     * @param c chaîne de caractère à placer
    */
    void print (int x, int y, char* c);

    /**
     * @brief affiche la fenêtre à partir d'une position 
     * 
     * @param x int coordonée en x
     * @param y int coordonnée en y
    */
    void draw (int x=0, int y=0);

    /**
     * @brief attend que l'utilisateur appuie sur une touche
    */
    void pause();

    /**
     * @brief lit et renvoie un caractère entré par l'utilisateur depuis la console
    */
    char getCh();

};

/**
 * @brief efface le contenu de la console
*/
void termClear ();

#endif
