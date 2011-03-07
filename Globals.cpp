#include "SDL/SDL.h"
#include "Globals.h"

namespace GameEng {
    
    Globals sys;

    Globals::Globals() : run(true), endingMessage("Player that won the game: "){
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != -1){
		screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
	} else {
		SDL_Quit();
	}
    }

    Globals::~Globals(){
	SDL_Quit();
    }
}
