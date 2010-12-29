#include "SDL/SDL.h"
#include "Globals.h"

namespace Game{
    
    Globals sys;

    Globals::Globals(){
	SCREEN_HEIGHT = 480;
	SCREEN_WIDTH = 640;
	SCREEN_BPP = 32;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != -1){
		screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
	}
    }

    Globals::~Globals(){
	SDL_Quit();
    }
}
