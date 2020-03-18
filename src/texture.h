#ifndef TXTRE_H
#define TXTRE_H
#include <SDL.h>

class texture{
public:
	texture(const char* fileName, SDL_Renderer* renderer, SDL_Window* window, int w, int h);
	void draw(int x, int y, SDL_RendererFlip flip);
	void drawFrame(int x, int y, int frame, SDL_RendererFlip flip);

	int getWidth();
	int getHeight();
	int* getPixel(int x, int y);

private:
	SDL_Window* Window;
	SDL_Renderer* Renderer;
	SDL_Texture* Texture;
	SDL_Surface* Surface;
	int width;
	int height;
	SDL_Rect srcRect;
 	SDL_Rect destRect;
};

#endif