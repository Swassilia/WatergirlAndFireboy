/**
@brief Module qui définit une classe pour gérer un jeu avec SDL
@file MenuSdl.h
@date 2023/03/14
*/
#ifndef _SDLJEU_H
#define _SDLJEU_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../core/Menu.h"

/**
 * @brief classe gerant l'affichage en image du jeu
*/
class Image {

public:

    /**
     * @brief Constructeur par défaut de la classe Image
     */
    Image();

    /**
     * @brief Destructeur qui libère la mémoire allouée pour la classe Image
     */
    ~Image();

    /**
     * @brief fonction qui charge une image à partir d'un fichier et crée une texture SDL
     * 
     * @param filename pointeur sur la chaîne de carcatère du nom du fichier à sauver
     * @param renderer SDL_Renderer
     */
    void loadFromFile (const char* filename, SDL_Renderer * renderer);

    /**
     * @brief fonction qui crée une texture SDL
     * 
     * @param renderer SDL_Renderer
     */
    void loadFromCurrentSurface (SDL_Renderer * renderer);

    /**
     * @brief dessine la texture SDL de l'image sur le rendu SDL_Renderer
     * 
     * @param renderer SDL_Renderer
     * @param x int coordonnée
     * @param y int coordonnée
     * @param w int largeur de la texture
     * @param h int hauteur de la texture
     */
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);

    /**
     * @brief accesseur qui retourne un pointeur vers la texture SDL de l'image
     * 
     * @return pointeur vers SDL_Texture
     */
    SDL_Texture * getTexture() const;

    /**
     * @brief mutateur qui définit la surface SDL de l'image
     * 
     * @param surf SDL_Surface (pointeur)
     */
    void setSurface(SDL_Surface * surf);


private:

    /**
     * @brief pointeur vers une structure SDL_Surface qui contient les données de l'image chargée
     */
    SDL_Surface * surface;

    /**
     * @brief pointeur vers une structure SDL_Texture qui contient les données de la texture SDL créée à partir de l'image chargée
     */
    SDL_Texture * texture;

    /**
     * @brief  booléen qui indique si la texture a été modifiée depuis la dernière fois qu'elle a été dessinée
     */
    bool has_Changed;

};

//=========================================//
//=============Boucle Affichage============//

/**
 * @brief classe gerant l'affichage du menu principale
 * 
 */
class SDLMenu{
    public:

    /**
     * @brief Constructeur par défaut de la classe SDLMenu qui
     * initialise les membres de la classe et crée la fenêtre et le rendu SDL
     * 
     */
    SDLMenu();
    /**
     * @brief Destructeur qui libère la mémoire allouée pour la fenêtre
     */
    ~SDLMenu ();

    /**
     * @brief verifie si un bouton a été cliqué dessus ou pas
     * 
     * @param x 
     * @param y 
     * @param rect 
     * @return true 
     * @return false 
     */
    bool estClique(int x,int y,SDL_Rect rect);

    /**
     * @brief affiche le menu principale du jeu avant le debut du jeu
     * 
     */
    void afficherMenu(SDL_Renderer* renderer);


    private :

    /**
     * @brief fenêtre SDL dans laquelle le jeu est affiché
     */
    SDL_Window * fenetre;
    /**
     * @brief objet qui permet de dessiner dans une fenêtre
     */
    SDL_Renderer * renderer;
    /**
     * @brief police de caractère
     */
    TTF_Font * font;
    /**
     * @brief image qui contient le texte dessiné avec la police "font"
     */
    Image font_im;
    /**
     * @brief couleur du texte
     */
    SDL_Color font_color;


    /**
     *  images représentant le menu
     * 
     */
    Image titre;
    Image boutonSDL;
    Image boutonTXT;
    Image boutonQuit;

};
