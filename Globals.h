#ifndef GLOBALS_H 
#define GLOBALS_H 

#include "SDL/SDL.h"

namespace Game{

    struct Globals{
	Globals();
	~Globals();
	SDL_Surface* screen;

	int SCREEN_HEIGHT;
	int SCREEN_WIDTH;
	int SCREEN_BPP;
    };

    extern Globals sys;
}
#endif
