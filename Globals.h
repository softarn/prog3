#ifndef GLOBALS_H 
#define GLOBALS_H 

#include "SDL/SDL.h"

namespace GameEng {

    struct Globals{
	Globals();
	~Globals();
	SDL_Surface* screen;

	static const int SCREEN_HEIGHT = 600;
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_BPP = 32;
    };

    extern Globals sys;
}
#endif
