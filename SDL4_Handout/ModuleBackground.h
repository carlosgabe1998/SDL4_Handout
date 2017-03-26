#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();
	enum upandown {
		arriba,
		neutro,
		abajo
	};
	bool Start();
	update_status Update();

	void updown() {

		if (ud == 10) {
			bouyancy = arriba;
			timelapse = 3;
		}
		if(ud==0 && timelapse>0){
			bouyancy = neutro;
			timelapse--;
		}
		else if (ud == 0 && timelapse==0) {
			bouyancy = abajo;

		}

		if (bouyancy == abajo) {

			ud++;
		}
		else if(bouyancy == arriba){
			ud--;
		}

		
	}

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	Animation flag;
	SDL_Rect ship;
	Animation girl;
	Animation graymans;
	Animation coffeman;
	Animation bluehat;
	Animation brownhat;
	Animation pman;
	unsigned short ud = 0;
	upandown bouyancy = abajo;
	unsigned short timelapse = 3;


};

#endif