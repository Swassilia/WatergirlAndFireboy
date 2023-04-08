#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


struct Animation
{
    int nbframe;
    int tmp;
    SDL_Texture* texture;
    SDL_Rect frame[3];
};
int Animation(SDL_Texture* texture, int frame_width, int frame_height, int frame_time);

void Boucle(SDL_Renderer* renderer, int x, int y);