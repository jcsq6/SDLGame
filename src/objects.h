#ifndef HEADER_H
#define HEADER_H

#include <SDL.h>
#include <SDL_image.h>
#include "texture.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern bool running;

void initSDL(const char* title, int xpos, int ypos, int height, int width, int flags);
void quitSDL();

class object{
public:
	object();
	object(int X, int Y);
	void update(int xVel, int yVel);
	void setPos(int X, int Y);
	int x();
	int y();
private:
	int _x;
	int _y;
};
#endif