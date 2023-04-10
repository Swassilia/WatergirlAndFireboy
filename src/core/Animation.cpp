
#include <stdlib.h>
#include "Animation.h"  

    Animation:: Animation(SDL_Texture* texture, int frame_width, int frame_height, int frame_time) {
        this->texture = texture;
        this->tmp = frame_time;
        for (int i = 0; i < 3; i++) {
            frame[i].x = i * frame_width;
            frame[i].y = 0;
            frame[i].w = frame_width;
            frame[i].h = frame_height;
        }
    }
    
    void Animation::Boucle(SDL_Renderer* renderer, int x, int y) {
        bool running = true;
        while (running) {
            // Handle events (e.g. window close)
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    running = false;
                }
            }
    
            // Render the current frame
            int current_frame = (SDL_GetTicks() / tmp) % 3;
            SDL_RenderClear(renderer);
            SDL_Rect dest = { x, y, frame[current_frame].w, frame[current_frame].h };
            SDL_RenderCopy(renderer, texture, &frame[current_frame], &dest);
            SDL_RenderPresent(renderer);
    
            // Delay until the next frame
            SDL_Delay(tmp);
        }
    }

