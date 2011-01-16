#include "SDL/SDL.h"
#include <string>
#include <vector>
#include "Timer.h"
#include "GameEngine.h"
#include "Globals.h"
namespace GameEng {

	GameEngine::GameEngine(){
	}

	GameEngine::~GameEngine(){
		for(unsigned int i=0; i < comps.size(); i++)
			delete comps[i];	
	}

	int GameEngine::run(){
		bool quit = false;

		Timer timer;

		timer.start();
		while( quit == false ){
			SDL_Event event;
			//While there's events to handle
			while( SDL_PollEvent( &event ) ) {
				//If the user has Xed out the window
				if( event.type == SDL_QUIT ) {
					//Quit the program
					quit = true;
				}

				for(unsigned int i=0; i < comps.size(); i++) {
					comps[i]->handle_input(event);
				}
			}


			for(unsigned int i=0; i < comps.size(); i++) {
				comps[i]->tick();
			}

			//Restart delta timer
			timer.start();

			//Fill the screen white
			SDL_FillRect( sys.screen, &sys.screen->clip_rect, SDL_MapRGB( sys.screen->format, 0xFF, 0xFF, 0xFF ) );

			for(unsigned int i=0; i < comps.size(); i++) {
				comps[i]->draw();
			}
			//Update the screen
			if( SDL_Flip( sys.screen ) == -1 ) {
				return 1;
			}

			//Cap the frame rate
			if ( timer.get_ticks() < 1000 / FRAMES_PER_SECOND ) {
				SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - timer.get_ticks());
			}
		}
	}

	void GameEngine::add(Sprite* spr){
		comps.push_back(spr);
	}
}
