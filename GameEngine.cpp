#include "SDL/SDL.h"
#include <string>
#include <vector>
#include <iostream>
#include "Timer.h"
#include "SpriteInput.h"
#include "GameEngine.h"
#include "Globals.h"

namespace GameEng {

    GameEngine::~GameEngine(){
	for(unsigned int i=0; i < comps.size(); i++)
	    delete comps[i];
    }

    int GameEngine::run(){
	Timer timer;

	timer.start();
	while( sys.run ){
	    SDL_Event event;

	    timer.start();

	    while( SDL_PollEvent( &event ) ) {

		if( event.type == SDL_QUIT )
		    sys.run = false;

		for(unsigned int i=0; i < comps.size(); i++) {
		    SpriteInput *si = dynamic_cast<SpriteInput*>(comps[i]);
		    if(si)
			si->handle_input(event);
		}
	    }


	    for(unsigned int i=0; i < comps.size(); i++) {
		comps[i]->tick();
		SpriteInput *si = dynamic_cast<SpriteInput*>(comps[i]);
		if(si)
		    si->collision(comps);
	    }

	    //Fill the screen 
	    SDL_FillRect( sys.screen, &sys.screen->clip_rect, SDL_MapRGB( sys.screen->format, 0xF4, 0x93, 0x43 ) );

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
