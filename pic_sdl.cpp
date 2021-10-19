#include<iostream>
#include<SDL2/SDL.h>

SDL_Window* window;
SDL_Surface* surface;
SDL_Surface* ImageSurface;

bool init(){ //method to initialize an SDL window
    bool success = true;

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        std::cout<<"An error occured"<<SDL_GetError();
        success=false;
    }
    else{
        
        window = SDL_CreateWindow("Another sample window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            320,
            240,
            0);
        if(window==NULL){
            success=false;
            std::cout<<"Window failed to be created";
        }
        else{
            surface = SDL_GetWindowSurface(window);
        }

    }

    return success;
}
//method to load an image surface
bool loadImageSurface(){
    bool success=true;
    ImageSurface = SDL_LoadBMP("download.bmp");//load the image file
    if(ImageSurface==NULL){
        success=false;
        std::cout<<"Failed to load media "<<SDL_GetError();
    }
    return success;
}


void closeWindow(){
    SDL_FreeSurface(surface); //free memory held by surface
    SDL_DestroyWindow(window); // free memory held by window
    SDL_Quit(); // quit all sdl functions
}

int main(){

    bool isInitialised= init();
    if(loadImageSurface()){ // if the image is loaded 
        SDL_BlitSurface(ImageSurface,NULL,surface,NULL); // copy the image on to the window surface
        SDL_UpdateWindowSurface(window); // update the window
        SDL_Delay(2000);// delay before closing
    } 
    if(isInitialised){
        closeWindow();
    }

}