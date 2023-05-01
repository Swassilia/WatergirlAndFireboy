/**
@brief Module qui définit une classe pour gérer un jeu avec SDL
@file JeuSdl.h
@date 2023/03/14
*/
#ifndef _SDLJEU_H
#define _SDLJEU_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../core/Jeu.h"

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
/**
 * @brief mettre à jour un compteur de temps (chrono)
*/
Uint32 chrono_callback(Uint32 interval, void *param);
//=========================================//


/**
 * @brief classe gerant le jeu avec un affichage SDL
*/
class SDLSimple {


public :

    /**
     * @brief Constructeur par défaut de la classe SDLSimple qui 
     * @brief initialise les membres de la classe et crée la fenêtre et le rendu SDL
     */
    SDLSimple ();

    /**
     * @brief Destructeur qui libère la mémoire allouée pour la fenêtre
     */
    ~SDLSimple ();

    /**
     * @brief contient la boucle principale du jeu SDL
     * @def gère les entrées utilisateur, les mises à jour de jeu et le rendu du jeu
     */
    void sdlBoucle ();

    /**
     * @brief dessine le plateau de jeu sur le rendu SDL en utilisant les images
     * 
     * @param pla plateau du jeu
     */
    void sdlAff (const Plateau &pla);

    /**
     * @brief affiche l'écran de fin de jeu lorsque le joueur a perdu
    */
    void afficherGameOver();

private :

    /**
     * @brief Instance de la classe Jeu
     */
	Jeu jeu;
    
    /**
     * @brief fenêtre SDL dans laquelle le jeu est affiché
     */
    SDL_Window * window;
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
     * @brief  objet qui contient un fichier audio
     */
    Mix_Chunk * sound;
    /**
     * @brief  booléen qui indique si le son est activé ou non
     */
    bool withSound;


    /**
     * @brief  identifiant de timer SDL utilisé pour gérer le chronomètre du jeu
     */
    SDL_TimerID time;
    /**
     * @brief  mage qui contient le texte affichant le temps écoulé depuis le début du jeu
     */
    Image im_chrono;
    /**
     * @brief  la couleur du texte du chronomètre
     */
    SDL_Color chrono_couleur;
    
   
   /**
    * @brief images qui représentent les différentes zones du jeu
   */
    Image riviere1;
    Image lava1;
    Image vert1;
   
    /**
     * @brief images représentant les personnages du jeu
    */
    Image im_perso_eau;
    Image im_perso_feu;

    /**
     * @brief images représentant les diamants
    */
    Image im_diamond_eau;
    Image im_diamond_feu;

    /**
     * @brief images représentant les différents éléments du décor
    */
    Image im_mur;
    Image im_fond;
    Image im_bloc;

    /**
     *  images représentant les portes
    */
    Image im_porte_eau;
    Image im_porte_feu;


    /**
     * @brief booléens qui indiquent si une souris ou un clavier est utilisé pour contrôler le jeu
    */
    bool souris;
    bool touche;
};

#endif
