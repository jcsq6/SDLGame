#include "eventHandler.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "objects.h"

using namespace std;

eventHandler::eventHandler(){
	mouseStates = new bool[3];
	for(int i = 0; i < 3; i++){
		mouseStates[i] = false;
	}
}

void eventHandler::loadKey(Key k){
	keys[k.getName()] = k;
}

void eventHandler::getStates(){
	SDL_Event event;

	while (SDL_PollEvent(&event)){
		auto it = keys.begin();
		switch(event.type){
		case SDL_KEYDOWN:
			for(; it != keys.end(); it++){
      			if(event.key.keysym.sym == it->second.keyCode()){
      				it->second.setState(true);
      			}
      			cout << it->first << " : " << keys[it->first].isPressed() << endl;
  			}
  			break;
  		case SDL_KEYUP:
			for(; it != keys.end(); it++){
      			if(event.key.keysym.sym == it->second.keyCode()){
      				it->second.setState(false);
      			}
      			cout << it->first << " : " << keys[it->first].isPressed() << endl;
  			}
  			break;
  		case  SDL_MOUSEBUTTONDOWN:
  			switch(event.button.button){
  			case SDL_BUTTON_LEFT:
  				mouseStates[mouseButton::left] = true;
  				break;
  			case SDL_BUTTON_MIDDLE:
  				mouseStates[mouseButton::middle] = true;
  				break;
  			case SDL_BUTTON_RIGHT:
  				mouseStates[mouseButton::right] = true;
  				break;
  			}
  			break;
  		case  SDL_MOUSEBUTTONUP:
  			switch(event.button.button){
  			case SDL_BUTTON_LEFT:
  				mouseStates[mouseButton::left] = false;
  				break;
  			case SDL_BUTTON_MIDDLE:
  				mouseStates[mouseButton::middle] = false;
  				break;
  			case SDL_BUTTON_RIGHT:
  				mouseStates[mouseButton::right] = false;
  				break;
  			}
  			break;
  		case SDL_MOUSEMOTION:
  			mousePos.setPos(event.motion.x, event.motion.y);
  			break;
  		case SDL_QUIT:
  			running = false;
  			break;
		}
	}

}

bool eventHandler::keyIsPressed(string name){
	if(keys[name].isPressed()){
		return true;
	}
	else{
		return false;
	}
}

bool eventHandler::mouseIsPressed(mouseButton button){
	return mouseStates[button];
}

void eventHandler::getMousePos(object &pos){
	pos.setPos(mousePos.x(), mousePos.y());
}

Key::Key(string name, SDL_Keycode k){
	code = name;
	key_code = k;
	isDown = false;
}

Key::Key(){
	code = "null";
	key_code = NULL;
	isDown = false;
}

bool Key::isPressed(){
	return isDown;
}

SDL_Keycode Key::keyCode(){
	return key_code;
}
void Key::setState(bool state){
	isDown = state;
}

string Key::getName(){
	return code;
}