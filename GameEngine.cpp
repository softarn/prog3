#include "SDL/SDL.h"
#include <string>
#include <vector>
#include "Timer.h"
#include "GameEngine.h"

namespace Game{

	GameEngine::GameEngine(int sw, int sh, int sbpp, int sfps, std::string stitle) :
		screen_w(sw), screen_h(sh), screen_bpp(sbpp),fps(sfps), title(stitle) {}

	GameEngine::~GameEngine(){
		for(unsigned int i=0; i < comps.size(); i++)
			delete comps[i];	
	}

	int GameEngine::run(){
		bool quit = false;
		Timer timer;

		timer.start();
		while( quit == false ){

			if ( timer.get_ticks() < 1000 / fps ) {
				SDL_Delay( ( 1000 / fps ) - timer.get_ticks());
			}
		}
	}

	void GameEngine::add(int* spr){
		comps.push_back(spr);
	}
}
