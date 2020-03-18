#include "objects.h"
#include <SDL.h>
#include <SDL_image.h>


void initSDL(const char* title, int xpos, int ypos, int height, int width, int flags){

 	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){

 		window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

 		if(window != 0){
 			renderer = SDL_CreateRenderer(window, -1, 0);
 		}
 	}

}
void quitSDL(){
	SDL_DestroyWindow(window);
 	SDL_DestroyRenderer(renderer);
 	SDL_Quit();
}

object::object(){
	_x = 0;
	_y = 0;
}

object::object(int X, int Y){
	_x = X;
	_y = Y;
}

void object::setPos(int X, int Y){
	_x = X;
	_y = Y;
}

void object::update(int xVel, int yVel){
	_x += xVel;
	_y += yVel;
}

int object::x(){
	return _x;
}

int object::y(){
	return _y;
}