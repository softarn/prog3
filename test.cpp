//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Image.h"
#include "Globals.h"
#include "Dot.h"
#include <string>
#include <iostream>

using namespace std;
using namespace GameEng;
using namespace Game;

//The frame rate
const int FRAMES_PER_SECOND = 80;

//The event structure
SDL_Event event;

//The timer
class Timer
{
	private:
		//The clock time when the timer started
		int startTicks;

		//The ticks stored when the timer was paused
		int pausedTicks;

		//The timer status
		bool paused;
		bool started;

	public:
		//Initializes variables
		Timer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		int get_ticks();

		//Checks the status of the timer
		bool is_started();
		bool is_paused();
};

Timer::Timer()
{
	//Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start()
{
	//Start the timer
	started = true;

	//Unpause the timer
	paused = false;

	//Get the current clock time
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	//Stop the timer
	started = false;

	//Unpause the timer
	paused = false;
}

void Timer::pause()
{
	//If the timer is running and isn't already paused
	if( ( started == true ) && ( paused == false ) )
	{
		//Pause the timer
		paused = true;

		//Calculate the paused ticks
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause()
{
	//If the timer is paused
	if( paused == true )
	{
		//Unpause the timer
		paused = false;

		//Reset the starting ticks
		startTicks = SDL_GetTicks() - pausedTicks;

		//Reset the paused ticks
		pausedTicks = 0;
	}
}

int Timer::get_ticks()
{
	//If the timer is running
	if( started == true )
	{
		//If the timer is paused
		if( paused == true )
		{
			//Return the number of ticks when the timer was paused
			return pausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			return SDL_GetTicks() - startTicks;
		}
	}

	//If the timer isn't running
	return 0;
}

bool Timer::is_started()
{
	return started;
}

bool Timer::is_paused()
{
	return paused;
}

int main( int argc, char* args[] )
{
	//Quit flag
	bool quit = false;

	//The dot that will be used
	Dot *myDot = new Dot(100, 200);

	//Keeps track of time since last rendering
	Timer timer;

	//Start delta timer
	timer.start();

	//While the user hasn't quit
	while( quit == false )
	{
		//While there's events to handle
		while( SDL_PollEvent( &event ) )
		{
			//If the user has Xed out the window
			if( event.type == SDL_QUIT )
			{
				//Quit the program
				quit = true;
			}
			
			myDot->handle_input(event);
		}

		//Move the dot
		myDot->tick();

		//Restart delta timer
		timer.start();

		//Fill the screen white
		SDL_FillRect( sys.screen, &sys.screen->clip_rect, SDL_MapRGB( sys.screen->format, 0xFF, 0xFF, 0xFF ) );

		//Show the dot on the screen
		myDot->draw();

		//Update the screen
		if( SDL_Flip( sys.screen ) == -1 )
		{
			return 1;
		}

		//Cap the frame rate
		if ( timer.get_ticks() < 1000 / FRAMES_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - timer.get_ticks());
		}
	}

	//Clean up
	return 0;
}
