#include<iostream>
#include<SDL2/SDL.h> //importing SDL
#include<SDL2/SDL_image.h> // importing SDL_image

int main(int argc ,char* args[]){

	if(SDL_Init(SDL_INIT_EVERYTHING)!=0){ //check if SDL is initialized
		std::cout<<"error occured"<<SDL_GetError();
		}
	else{
			//create an SDL window 
			SDL_Window* window = SDL_CreateWindow("sample",//name
						SDL_WINDOWPOS_CENTERED,//x position of window
						SDL_WINDOWPOS_CENTERED,//y position of window
						320,//width of the window
						240,//height of the window
						0);
			// create an SDL surface, surface is what renders stuff on window
			SDL_Surface* surface = SDL_GetWindowSurface(window);
			//make a rectangle on the surface
			SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0,0,0));
			//window needs to be updated inorder to see the changes made
			SDL_UpdateWindowSurface(window);
			//display the window for 2 seconds
			SDL_Delay(2000);
			//destroy the window to free memory
			SDL_DestroyWindow(window);
			//and finally quit SDL
			SDL_Quit();
	}

	return 0;
}
