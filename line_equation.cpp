#include<SDL2/SDL.h>
#include<iostream>

using namespace std;

int main(int arg, char* args[]){

    float x1 = atof(args[1]);
    float y1 = atof(args[2]);
    float x2 = atof(args[3]);
    float y2 = atof(args[4]);

    cout<<"X1 ="<<x1<<" Y1="<<y1<<"\n";
    cout<<"X2 ="<<x2<<" Y2="<<y2<<"\n";

    SDL_Event event;

    SDL_Window* Window = SDL_CreateWindow("Line with Equation of line",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    320,
    240,
    SDL_WINDOW_RESIZABLE);

    SDL_Renderer* Renderer = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);

    float slope = (y2-y1)/(x2-x1);
    float intercept = y1-(x1 * slope);

    SDL_SetRenderDrawColor(Renderer,0,0,0,1);
    SDL_RenderClear(Renderer);
    SDL_SetRenderDrawColor(Renderer,255,255,255,1);
    cout<<"Slope ="<<slope<<"\n";
    cout<<"Y-intercept ="<<intercept<<"\n";
    if (x2>x1){
    for(int i=int(x1); i <=int(x2); i++){
        float y = slope*i+intercept;
        SDL_RenderDrawPoint(Renderer,i,y);
        SDL_RenderPresent(Renderer);
        SDL_Delay(7);
    }
    }
    else{
        for(int i=int(x1); i >=int(x2); i--){
        float y = slope*i+intercept;
        SDL_RenderDrawPoint(Renderer,i,y);
        SDL_RenderPresent(Renderer);
        SDL_Delay(7);
    }

    }

    while(1){
        if(SDL_PollEvent(&event) && event.type==SDL_QUIT){
            break;
        }
    }

    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();

}