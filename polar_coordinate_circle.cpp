#include<iostream>
#include<SDL2/SDL.h>

using namespace std;

int main(int args, char* argv[]){

    float radius = atof(argv[1]);
    
    SDL_Window* Window = SDL_CreateWindow("Polar Coordinates Circle",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    320,
    240,
    SDL_WINDOW_RESIZABLE);

    SDL_Renderer* Render = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(Render,0,0,0,1);
    SDL_RenderClear(Render);
    SDL_SetRenderDrawColor(Render,255,255,255,1);
    
    SDL_Event event;

    int midx = 320/2;
    int midy = 240/2;

    SDL_RenderDrawPoint(Render,midx,midy);
    for(int j=1; j<=radius; j++){
        
        for(int i=0; i<=360; i++){

            float x = cos(i)*j;
            float y = sin(i)*j;
            SDL_RenderDrawPoint(Render,midx+x,midy+y);
            
            SDL_Delay(1);
    }
    SDL_RenderPresent(Render);
    }

    while(1){
        if(SDL_PollEvent(&event) && event.type==SDL_QUIT){
            break;
        }
    }

    SDL_DestroyRenderer(Render);
    SDL_DestroyWindow(Window);
    SDL_Quit();



}
