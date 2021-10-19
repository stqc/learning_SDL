#include<iostream>
#include<SDL2/SDL.h>

int main(){

    SDL_Window* window = SDL_CreateWindow("Circle With SDL",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    320,
    240,
    0);
    SDL_Renderer* render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    




}