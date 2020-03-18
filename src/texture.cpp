#include "texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


texture::texture(const char* fileName, SDL_Renderer* rend, SDL_Window* wind, int w, int h){

	Window = wind;
	Renderer = rend;

	IMG_Init(IMG_INIT_PNG);

	Surface = IMG_Load(fileName);

	if(Surface == NULL){
		std::cout << "failed to load image\n";
	}
	if(wind == NULL){
		std::cout << "failed to load window\n";
	}
	if(rend == NULL){
		std::cout << "failed to load renderer\n";
	}

 	Texture = SDL_CreateTextureFromSurface(rend, Surface);

 	width = w;
 	height = h;

 	srcRect.x = 0;
 	srcRect.y = 0;
 	srcRect.w = destRect.w = w;

	srcRect.h = destRect.h = h;
}

void texture::draw(int x, int y, SDL_RendererFlip flip){
 	destRect.x = x;
 	destRect.y = y;
 	
 	srcRect.x = 0;
 	srcRect.y = 0;

 	SDL_RenderCopyEx(Renderer, Texture, &srcRect, &destRect, 0, 0, flip);
}

int* texture::getPixel(int x, int y){
	static int Color[4];
	SDL_PixelFormat *fmt;
	Uint32 temp, pixel;
	Uint32 *pixels = (Uint32 *)Surface->pixels;
	Uint8 red, green, blue, alpha;

	fmt = Surface->format;
	SDL_LockSurface(Surface);
	pixel = pixels[(y * Surface->w) + x];
	SDL_UnlockSurface(Surface);

	/* Get Red component */
	temp = pixel & fmt->Rmask;  /* Isolate red component */
	temp = temp >> fmt->Rshift; /* Shift it down to 8-bit */
	temp = temp << fmt->Rloss;  /* Expand to a full 8-bit number */
	red = (Uint8)temp;

	/* Get Green component */
	temp = pixel & fmt->Gmask;  /* Isolate green component */
	temp = temp >> fmt->Gshift; /* Shift it down to 8-bit */
	temp = temp << fmt->Gloss;  /* Expand to a full 8-bit number */
	green = (Uint8)temp;

	/* Get Blue component */
	temp = pixel & fmt->Bmask;  /* Isolate blue component */
	temp = temp >> fmt->Bshift; /* Shift it down to 8-bit */
	temp = temp << fmt->Bloss;  /* Expand to a full 8-bit number */
	blue = (Uint8)temp;

	/* Get Alpha component */
	temp = pixel & fmt->Amask;  /* Isolate alpha component */
	temp = temp >> fmt->Ashift; /* Shift it down to 8-bit */
	temp = temp << fmt->Aloss;  /* Expand to a full 8-bit number */
	alpha = (Uint8)temp;

	Color[0] = red;
	Color[1] = green;
	Color[2] = blue;
	Color[3] = alpha;

	//printf("Pixel Color -> R: %d,  G: %d,  B: %d,  A: %d\n", red, green, blue, alpha);

	return Color;
}


void texture::drawFrame(int x, int y, int frame, SDL_RendererFlip flip){
 	srcRect.x = width * frame;
 	srcRect.y = 0;
 	srcRect.w = destRect.w = width;
 	srcRect.h = destRect.h = height;
 	destRect.x = x;
 	destRect.y = y;

 	SDL_RenderCopyEx(Renderer, Texture, &srcRect, &destRect, 0, 0, flip);
}

int texture::getWidth(){
	return width;
}

int texture::getHeight(){
	return height;
}