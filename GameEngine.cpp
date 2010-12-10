#include "SDL/SDL.h"
#include <string>
#include <vector>
#include "Timer.h"
#include "GameEngine.h"

namespace Game{

	GameEngine::GameEngine(int sw, int sh, int sbpp, int sfps, std::string stitle) :
		screen_w(sw), screen_h(sh), screen_bpp(sbpp),fps(sfps), title(stitle) {}

	GameEngine::~GameEngine(){}
	
	bool GameEngine::init()	{
		//Initialize all SDL subsystems
		if( SDL_Init(SDL_INIT_EVERYTHING ) == -1)
		{
			return false;
		}

		//Set up the screen
		screen = SDL_SetVideoMode(screen_w , screen_h, screen_bpp,
				SDL_SWSURFACE);

		//If there was an error in setting up the screen
		if( screen == NULL )
		{
			return false;
		}

		//Set the window caption
		//SDL_WM_SetCaption(title, NULL);


		//If everything initialized fine
		return true;
	}

	int GameEngine::run(){
		bool quit = false;
		Timer timer;

		if(!init()){
			return 1;
		}

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
