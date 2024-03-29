#include <cassert>
#include <time.h>
#include <iostream>
#include "JeuSdl.h"
#include <stdlib.h>


using namespace std;


const int TAILLE_SPRITE = 32;
const int MENU_MAX = 4;

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
//mettre à jour un compteur de temps (chrono)
Uint32 chrono_callback (Uint32 interval, void*param){
    int *chrono = (int *)param;
    (*chrono)--;
    return interval;
}
//=========================================//


// ============= CLASS Jeu =============== //

//Constructeur par défaut de la classe SDLSimple qui initialise les membres de la classe et crée la fenêtre et le rendu SDL
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
	 dimx = jeu.getPlateau().getDimx();
	 dimy = jeu.getPlateau().getDimy();
	 dimx = dimx * TAILLE_SPRITE;
	 dimy = dimy * TAILLE_SPRITE;
    
    // Creation de la fenetre
    window = SDL_CreateWindow("Fire Boy and Water Girl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx/1.03, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }
    //cout<<"window";
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
        im_mur.loadFromFile("data/mur.png",renderer);
        im_fond.loadFromFile("data/fond.jpg",renderer);
        im_diamond_eau.loadFromFile("data/diamondEau.png",renderer);
        im_diamond_feu.loadFromFile("data/diamondFeu.png",renderer);
        im_bloc.loadFromFile("data/bloc.png",renderer);
        im_perso_eau.loadFromFile("data/Eau.png",renderer);
        im_perso_feu.loadFromFile("data/Feu.png",renderer);
        im_porte_eau.loadFromFile("data/porteEau.png",renderer);
        im_porte_feu.loadFromFile("data/porteFeu.png",renderer);

        
        lava1.loadFromFile("data/lava-1.png",renderer);
        riviere1.loadFromFile("data/riviere-1.png",renderer);
        vert1.loadFromFile("data/vert-1.png",renderer);

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


        //anim = new Animation(renderer)
}

//Destructeur qui libère la mémoire allouée pour la fenêtre
SDLSimple::~SDLSimple(){
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//dessine le plateau de jeu sur le rendu SDL en utilisant les images
void SDLSimple::sdlAff(const Plateau &pla){
         
         //Remplir l'écran de blanc
         SDL_SetRenderDrawColor(renderer, 45,46,12,5);
         SDL_RenderClear(renderer);
         
         int x,y;
         const Personnage &eau = jeu.getPersonnageEau();
         const Personnage &feu = jeu.getPersonnageFeu();


         for (x=0;x<pla.getDimx();++x){ 
            for (y=0;y<pla.getDimy();++y)
            {   
                im_fond.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                if (pla.getPlateau(x,y)=='#') im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)==BLOC) im_bloc.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)==SPACE) im_fond.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)==BONUSFEU) im_diamond_feu.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)==BONUSEAU) im_diamond_eau.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)=='E') im_porte_eau.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)=='F') im_porte_feu.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)=='e') riviere1.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)=='f') lava1.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
                    else if(pla.getPlateau(x,y)=='v') vert1.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);   
            }
               
                                        
        //Affichage des personnages
        im_perso_eau.draw(renderer,eau.getPos().x*TAILLE_SPRITE,eau.getPos().y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
        im_perso_feu.draw(renderer,feu.getPos().x*TAILLE_SPRITE,feu.getPos().y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
        
    }
}

//affiche l'écran de fin de jeu lorsque le joueur a perdu
void SDLSimple::afficherGameOver() {

    const Plateau & pla=jeu.getPlateau();
    
    //Attendre 2 secondes avant d'afficher la fin de partie
    SDL_Delay(1000);

    //changer la couleur de la fenêtre
    SDL_SetRenderDrawColor(renderer, 143,130,65,5);
    SDL_RenderClear(renderer);

    //charger l'image "game Over"
    SDL_Surface* surface = IMG_Load("data/gameO.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Afficher l'image
    SDL_Rect rect = {160,140, pla.getDimx()*20, pla.getDimy()*20};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(renderer);

    SDL_Delay(4000); // Attendre 4 secondes avant de quitter le jeu
    SDL_Quit();
    exit(0);

}

void SDLSimple::afficherGagne() {

    const Plateau & pla=jeu.getPlateau();
    
    //Attendre 2 secondes avant d'afficher la fin de partie
    SDL_Delay(1000);

    //changer la couleur de la fenêtre
    SDL_SetRenderDrawColor(renderer, 255,255,255,5);
    SDL_RenderClear(renderer);

    //charger l'image "game Over"
    SDL_Surface* surface = IMG_Load("data/gagné.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Afficher l'image
    SDL_Rect rect = {160,140, pla.getDimx()*20, pla.getDimy()*20};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(renderer);

    SDL_Delay(4000); // Attendre 4 secondes avant de quitter le jeu
    SDL_Quit();
    exit(0);

}

//jouer de la musique tout le long du jeu
void SDLSimple:: jouerMusique(const char* filename) {
    // Initialiser SDL Mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cout << "Erreur lors de l'initialisation de SDL Mixer: " << Mix_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // Charger le fichier audio
    musique = Mix_LoadMUS("data/witch.mp3");
    if (musique == NULL) {
        cout << "Erreur lors du chargement du fichier audio: " << Mix_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // Jouer le fichier audio en boucle
    if (Mix_PlayMusic(musique, -1) < 0) {
        cout << "Erreur lors de la lecture du fichier audio: " << Mix_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
}

//arreter la musique quand le jeu est fini
void SDLSimple:: arreterMusique() {
    Mix_HaltMusic(); // Arrêter la musique
    Mix_FreeMusic(musique); // Libérer la mémoire allouée pour le fichier audio
    musique = NULL;
    Mix_CloseAudio(); // Fermer SDL Mixer
}

//contient la boucle principale du jeu SDL, gère les entrées utilisateur, les mises à jour de jeu et le rendu du jeu
void SDLSimple::sdlBoucle(){
    SDL_Event event;
    bool ouvert=false;
    Plateau pla=jeu.getPlateau();
    Uint32 t = SDL_GetTicks(), nt;
    jouerMusique("musique.mp3");

    while (!ouvert) {
        
       // afficherMenu(renderer,font);
        sdlAff(pla);
        
        nt = SDL_GetTicks();
        if (nt-t>500) {
            jeu.ActionAuto(pla);
            t = nt;
        }
        

		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&event)) {
            jeu.ajouteScore(pla);
            jeu.Gravite(true);
            if (jeu.succes(pla)) 
            {
                cout<<"gagné";
                ouvert=true;
                afficherGagne();
            }

            if (event.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
                
				switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_A:
					jeu.ActionClavier('q');    // car Y inverse
					break;
				case SDL_SCANCODE_W:
				    jeu.ActionClavier('z');     // car Y inverse
					break;
				case SDL_SCANCODE_D:
					jeu.ActionClavier('d');
					break;
				case SDL_SCANCODE_UP:
					jeu.ActionClavier('o');
					break;
                case SDL_SCANCODE_LEFT:
					jeu.ActionClavier('k');
					break;
        		case SDL_SCANCODE_RIGHT:
					jeu.ActionClavier('m');
					break;
                case SDL_SCANCODE_ESCAPE:
                    ouvert = true;
                    break;
				default: break;
				}
				
			}

            for(int i=0; i<30; i++)
            {
               if (jeu.perte(pla.getObjet(i)))
               {
                   ouvert=true;
                   afficherGameOver();
               };
                
            }
            
			if (event.type == SDL_QUIT) ouvert = true;           // Si l'utilisateur a clique sur la croix de fermeture
			

		}


        

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
    arreterMusique();
    
}
