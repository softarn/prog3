#ifndef GLOBALS_H 
#define GLOBALS_H 

#include "SDL/SDL.h"

namespace Game{

    struct Globals{
	Globals();
	~Globals();
	SDL_Surface* screen;

	static const int SCREEN_HEIGHT = 480;
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_BPP = 32;
    };

    extern Globals sys;
}
#endif
