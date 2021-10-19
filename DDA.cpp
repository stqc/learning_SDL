#include<SDL2/SDL.h>
#include<iostream>

using namespace std;

int main(int args, char* argc[]){

    float x1 = atoi(argc[1]);
    float y1 = atoi(argc[2]);
    float x2 = atoi(argc[3]);
    float y2 = atoi(argc[4]);

    SDL_Window* Window = SDL_CreateWindow("Digital Differential Analyzer",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    320,
    240,
    SDL_WINDOW_RESIZABLE);

    SDL_Renderer* render = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);

    float deltaY = y2-y1;
    float deltaX= x2-x1;
    float steps = abs(deltaY)>abs(deltaX)?abs(deltaY):abs(deltaX);
    float Yinc = deltaY/steps;
    float Xinc = deltaX/steps;

    cout<<"steps "<<steps<<endl;
    cout<<"delta x "<<deltaX<<" delta y "<<deltaY<<endl;
    cout<<"Xinc "<<Xinc<<" Yinc "<<Yinc<<endl;

    SDL_SetRenderDrawColor(render,0,0,0,1);
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render,255,255,255,1);
    for(int i=0; i< steps; i++){
        SDL_RenderDrawPoint(render,x1,y1);
        x1 += Xinc;
        y1 += Yinc;
        SDL_RenderPresent(render);
        SDL_Delay(5);
    }
    SDL_Event event;
    while(1){
        if(SDL_PollEvent(&event) && event.type == SDL_QUIT){
            break;
        }
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(Window);
    SDL_Quit();


}