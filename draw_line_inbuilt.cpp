#include<iostream>
#include<SDL2/SDL.h>

int main(){

    SDL_Window* Window = SDL_CreateWindow("Line using Inbuilt function",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    320,
    240,
    0);

    SDL_Renderer* Render = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    SDL_SetRenderDrawColor(Render,0,0,0,1);
    SDL_RenderClear(Render);
    SDL_SetRenderDrawColor(Render,255,255,255,1);
    SDL_RenderDrawLine(Render,0,0,320,240);
    SDL_RenderPresent(Render);
    while(1){
        if(SDL_PollEvent(&event) && event.type==SDL_QUIT){
            break;
        }
    }
    SDL_DestroyRenderer(Render);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}