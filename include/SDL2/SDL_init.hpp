#include "SDL.h"

int SLD_init(SDL_Renderer* renderer, SDL_Window* window, char* window_name, int window_width, int window_height){
    if(SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
    
    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0);
    if(!window) {
        SDL_Quit();
        return 1;
    }
    
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    renderer = SDL_CreateRenderer(window, -1, render_flags);
    if(!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
}