#ifndef GLOBALS_H 
#define GLOBALS_H 

#include "SDL/SDL.h"
#include <string>

namespace GameEng {

    struct Globals{
	Globals();
	~Globals();
	SDL_Surface* screen;

	static const int SCREEN_HEIGHT = 768;
	static const int SCREEN_WIDTH = 1366;
	static const int SCREEN_BPP = 32;

	bool run;
    };

    extern Globals sys;
}
#endif
