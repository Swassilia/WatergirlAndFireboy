#include <stdlib.h>

#include <iostream>
#include "JeuSdl.h"
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;
}

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_Changed = false;
}

Image::~Image()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    surface = nullptr;
    texture = nullptr;
    has_Changed = false;
}

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

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_Changed) {
        ok = SDL_UpdateTexture(texture,nullptr,surface->pixels,surface->pitch);
        //assert(ok == 0);
        has_Changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,nullptr,&r);
    //assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}

// ============= CLASS Jeu =============== //

SDLSimple::SDLSimple(): window(nullptr),renderer(nullptr){

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

	int dimx, dimy;
	// dimx = jeu.getConstPlateau().getdimX();
	// dimy = jeu.getConstPlateau().getdimY();
	// dimx = dimx * TAILLE_SPRITE;
	// dimy = dimy * TAILLE_SPRITE;
    

    // Creation de la fenetre
    window = SDL_CreateWindow("Fire Boy and Water Girl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx/2, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
        im_mur.loadFromFile("data/mur.png",renderer);
        im_fond.loadFromFile("data/fond.jpg",renderer);
        im_diamond_eau.loadFromFile("data/diamondEau.png",renderer);
        im_diamond_feu.loadFromFile("data/diamondFeu.png",renderer);

    
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
        
}

SDLSimple::~SDLSimple(){
    //if (withSound) Mix_Quit();
    //TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

 void SDLSimple::sdlAff(){
         // Avion &av= jeu.getAvion();
         int x,y;
         const Plateau &pla=jeu.getPlateau();
         const Personnage &eau = jeu.getPersonnageEau();
         const Personnage &feu = jeu.getPersonnageFeu();
         SDL_Event event;
         bool ouvert=false;
         Uint32 t = SDL_GetTicks(), nt;
         while(!ouvert){
             nt = SDL_GetTicks();
         if (nt-t>500) {
             //jeu.actionsAutomatiques();
             t = nt;
         }
             while(SDL_PollEvent(&event)) {
              if (event.type==SDL_QUIT) 
                 ouvert=true;
                 else if (event.type == SDL_KEYDOWN) {  // Si une touche est enfoncee
                 bool mangeObstacle = false;
 				switch (event.key.keysym.scancode) {
 				case SDL_SCANCODE_UP:
 					jeu.ActionClavier('q');   
 					break;
                     case SDL_SCANCODE_DOWN:
 					jeu.ActionClavier('z');
                     break;  
 					case SDL_SCANCODE_ESCAPE:
                     case SDL_SCANCODE_Q:
                     ouvert=false;
                     break;
                     default:break;}
             }
         }
         for(unsigned int i=0; i<pla.getDimx(); i++){
            for (unsigned int j=0; j<pla.getDimy(); j++){
                SDL_Surface* mur = IMG_Load("data/mur.png");
                SDL_Surface* fond = IMG_Load("data/fond.png"); 
                SDL_Texture* c=SDL_CreateTextureFromSurface(renderer, mur);
                SDL_Texture* c=SDL_CreateTextureFromSurface(renderer, fond);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, c, NULL, NULL);
                SDL_DestroyTexture(c);

            }
         }
         }
 }
      
//          int x;
//          int y;
      
//          SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);        
//          for (x=0; x<pla.getdimX(); ++x){
//              for (y=0; y<pla.getdimY(); y++){
//                  if (pla.getXY(x,y)=='O'){
//                      im_bonus.draw(renderer,obs.getX_bo()*TAILLE_SPRITE,obs.getY_bo()*TAILLE_SPRITE,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
//                  }
//                  if (pla.getXY(x,y)=='.')
//                  {
//                      im_ennemi1.draw(renderer,obs.getX_en1()*TAILLE_SPRITE,obs.getY_en1()*TAILLE_SPRITE,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
//                      im_ennemi2.draw(renderer,obs.getX_en2()*TAILLE_SPRITE,obs.getY_en2()*TAILLE_SPRITE,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
//                      im_ennemi3.draw(renderer,obs.getX_en3()*TAILLE_SPRITE,obs.getY_en3()*TAILLE_SPRITE,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
//                  }
//                  }}
//          //affichage de l'avion
//          im_avion.draw(renderer, av.getX_coordonnee()*TAILLE_SPRITE,av.getY_coordonnee()*TAILLE_SPRITE, TAILLE_SPRITE*2, TAILLE_SPRITE*3);
//          SDL_RenderPresent(renderer);
//          }
//          SDL_DestroyRenderer(renderer);
  


