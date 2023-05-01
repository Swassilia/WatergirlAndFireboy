#include <cassert>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "MenuSdl.h"


using namespace std;


const int TAILLE_SPRITE = 32;
// const int MENU_MAX = 4;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;
}

// ============= CLASS IMAGE =============== //

//Constructeur par défaut de la classe Image
Image::Image () {
    surface = nullptr;
    texture = nullptr;
    has_Changed = false;
}

//Destructeur qui libère la mémoire allouée pour la classe Image
Image::~Image()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    surface = nullptr;
    texture = nullptr;
    has_Changed = false;
}

//fonction qui charge une image à partir d'un fichier et crée une texture SDL
void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == nullptr) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

//fonction qui crée une texture SDL
void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

//dessine la texture SDL de l'image sur le rendu SDL_Renderer
void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<=0 )?surface->w:w;
    r.h = (h<=0)?surface->h:h;

    if (has_Changed) {
        ok = SDL_UpdateTexture(texture,nullptr,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_Changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,nullptr,&r);
    assert(ok == 0);
}

//accesseur qui retourne un pointeur vers la texture SDL de l'image
SDL_Texture * Image::getTexture() const {return texture;}

//mutateur qui définit la surface SDL de l'image
void Image::setSurface(SDL_Surface * surf) {surface = surf;}



//=========================================//
//=============Boucle Affichage============//

//Constructeur par défaut de la classe SDLSimple qui initialise les membres de la classe et crée la fenêtre et le rendu SDL
SDLMenu::SDLMenu(): window(nullptr),renderer(nullptr){

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

   
    // Creation de la fenetre
    fenetre = SDL_CreateWindow("Fire Boy and Water Girl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx/1.03, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (fenetre == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }
    //cout<<"window";
    renderer = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
        titre.loadFromFile("data/titre.png",renderer);
        boutonSDL.loadFromFile("data/iconeSDL.png",renderer);
        boutonTXT.loadFromFile("data/iconeTXT.png",renderer);
        boutonQuit.loadFromFile("data/iconeQuit.png",renderer);
    //cout<<"image";
    //FONT
        if (TTF_Init() < 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        }
        font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
        if (font == NULL)
            font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
        if (font == NULL) {
                cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
                SDL_Quit(); 
                exit(1);
        }
        font_color.r = 50;font_color.g = 50;font_color.b = 255;
        font_im.setSurface(TTF_RenderText_Solid(font,"Fire Boy and Water Girl",font_color));
        font_im.loadFromCurrentSurface(renderer);
        //cout<<"font";


}

//Destructeur qui libère la mémoire allouée pour la fenêtre
SDLMenu::~SDLMenu(){
    //if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}

bool SDLMenu::estClique(int x, int y,SDL_Rect rect){
    return (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h);
}

void SDLMenu::afficherMenu(SDL_Renderer* renderer)
{

    SDL_SetRenderDrawColor(renderer, 143,130,65, 255);
    SDL_RenderClear(renderer);

    SDL_Surface* surface = TTF_RenderText_Solid(font, "Menu", {255,255,255});
     // Couleur du texte
    //SDL_Color textColor = {0, 0, 0, 255};

    titre.draw(renderer,8*TAILLE_SPRITE,2*TAILLE_SPRITE,500,300);
    boutonSDL.draw(renderer,2*TAILLE_SPRITE,12*TAILLE_SPRITE,400,100);
    boutonTXT.draw(renderer,18*TAILLE_SPRITE,12*TAILLE_SPRITE,400,100);
    boutonQuit.draw(renderer,10*TAILLE_SPRITE,17*TAILLE_SPRITE,400,100);

    SDL_Event event;
    bool menuActif = true;
    if (SDL_PollEvent(&event))
    {   
        switch (event.type)
        {
        case SDL_QUIT:
            menuActif = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (isClicked(event.button.x, event.button.y, boutonSDL.getRect()))
            {
                system("bin/sdl");
            }
            else if (isClicked(event.button.x, event.button.y, boutonTXT.getRect()))
            {
                system("bin/text");
            }
            else if (isClicked(event.button.x, event.button.y, boutonQuit.getRect()))
            {
                menuActif = false;
            }
            break;

        default:
            break;
        }
}

}