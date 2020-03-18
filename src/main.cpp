#include "objects.h"
#include "texture.h"
#include "eventHandler.h"
#include <iostream>

#undef main

using namespace std;

SDL_Window* window = 0;
SDL_Renderer* renderer = 0;

bool running = true;

eventHandler handler;

enum class direction{
    right,
    left,
    none
};

int main(){

    initSDL("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, SDL_WINDOW_SHOWN);

    texture map("map.png", renderer, window, 960, 540);
    object hero(0, 0);
    object mouse(0, 0);

    Key RightKey("right", SDLK_RIGHT);
    Key LeftKey("left", SDLK_LEFT);

    handler.loadKey(RightKey);
    handler.loadKey(LeftKey);

    int *rgb = map.getPixel(mouse.x(), mouse.y());

    int mapFrame = 0;

    while(running){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        handler.getStates();
        handler.getMousePos(mouse);

        rgb = map.getPixel(mouse.x(), mouse.y());

        cout << rgb[0] << ", " << rgb[1] << ", " << rgb[2] << ", " << rgb[3] <<  " : y = " << mouse.y() << endl;

        cout << SDL_GetError() << endl;
        SDL_Delay(50);

        map.drawFrame(0, 0, mapFrame, SDL_FLIP_NONE);

        SDL_RenderPresent(renderer);
    }

    quitSDL();

    return 0;
}