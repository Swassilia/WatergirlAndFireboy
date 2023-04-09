#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "../core/Jeu.h"

//! \brief Pour gérer une image avec SDL2
class Image {


public:
     Image();
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_Changed;

};



/**
    La classe gerant le jeu avec un affichage SDL
*/
class SDLSimple {


public :

    SDLSimple ();
    ~SDLSimple ();
    void sdlBoucle ();
    void sdlAff ();

private :

	Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound;

    Image im_perso_eau;
    Image im_perso_feu;

    Image im_diamond_eau;
    Image im_diamond_feu;

    Image im_mur;
    Image im_fond;


    bool souris;
    bool touche;
};

#endif
