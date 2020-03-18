#ifndef EVENT_H
#define EVENT_H

#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <math.h>
#include <string>
#include "objects.h"

using namespace std;

enum mouseButton{
	left,
	middle,
	right
};

class Key{
public:
	Key();
	Key(string name, SDL_Keycode k);
	bool isPressed();
	string getName();
	SDL_Keycode keyCode();
	void setState(bool state);
private:
	string code;
	bool isDown;
	SDL_Keycode key_code;
};

class eventHandler{
public:
	eventHandler();
	void loadKey(Key k);
	void getStates();
	bool keyIsPressed(string name);
	bool mouseIsPressed(mouseButton button);
	void getMousePos(object &pos);
private:
	map<string, Key> keys;
	bool* mouseStates;
	object mousePos;
};


#endif