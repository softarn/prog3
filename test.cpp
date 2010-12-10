//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Image.h"
#include <string>
#include <iostream>

using namespace std;

//The screen sttributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 500;

//The attributes of the dot
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;
const int DOT_VELY = 250;
const int DOT_VELX = 20;

const float GRAVITY = 1.0f;
const float FRICTION = 0.9999f;

//The surfaces
Image *dot = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The dot
class Dot
{
	private:
		//The X and Y offsets of the dot
		float x, y;

		//The velocity of the dot
		float xVel, yVel;

	public:
		//Initializes the variables
		Dot(int x, int y);

		//Takes key presses and adjusts the dot's velocity
		void handle_input();

		//Moves the dot
		void move( Uint32 deltaTicks );

		//Shows the dot on the screen
		void show();

		void gravity();

		void friction();
};

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

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = x;
	offset.y = y;

	//Blit
	SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	//If there was an error in setting up the screen
	if( screen == NULL )
	{
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption( "Move the Dot", NULL );

	//If everything initialized fine
	return true;
}

bool load_files()
{
	//Load the dot image
	dot = new Image("dot.bmp");

	//If there was a problem in loading the dot
	if( dot == NULL )
	{
		return false;
	}

	//If everything loaded fine
	return true;
}

void clean_up()
{
	//Free the surface
	delete dot;

	//Quit SDL
	SDL_Quit();
}

Dot::Dot(int x = 100, int y = 200)
{
	//Initialize the offsets
	x = 100;
	y = 200;

	//Initialize the velocity
	xVel = 0;
	yVel = 0;
}

void Dot::handle_input()
{
	//If a key was pressed
	if( event.type == SDL_KEYDOWN )
	{
		//Adjust the velocity
		switch( event.key.keysym.sym )
		{
			//case SDLK_UP: yVel -= DOT_VEL; break;
			//case SDLK_DOWN: yVel += DOT_VEL; break;

			case SDLK_SPACE: 
				if( y + DOT_HEIGHT >= SCREEN_HEIGHT - 10 && yVel > -250 ){
					int direction;
					if(yVel > 0)
						direction = 1;
					else
						direction = -1;
					yVel += DOT_VELY * direction;
				} break;
		}
	}
	
	//Get the keystates
	Uint8 *keystates = SDL_GetKeyState( NULL );

	//If left is pressed
	if( keystates[ SDLK_LEFT ] && xVel > -200 )
	{
		xVel -= DOT_VELX;
	}

	//If right is pressed
	if( keystates[ SDLK_RIGHT ] && xVel < 200)
	{
		xVel += DOT_VELX;
	}
}

void Dot::move( Uint32 deltaTicks )
{
	//Move the dot left or right
	x += xVel * ( deltaTicks / 1000.f );

	//If the dot went too far to the left
	if( x < 0 )
	{
		//Move back
		x = 0;
		xVel = -(xVel - 5);
	}
	//or the right
	else if( x + DOT_WIDTH > SCREEN_WIDTH )
	{
		//Move back
		x = SCREEN_WIDTH - DOT_WIDTH;
		xVel = -(xVel - 20);
	}

	//Move the dot up or down
	y += yVel * ( deltaTicks / 1000.f );

	//If the dot went too far up
	if( y < 0 )
	{
		//Move back
		y = 0;
		yVel = -yVel;
	}
	//or down
	else if( y + DOT_HEIGHT > SCREEN_HEIGHT )
	{
		//Move back
		y = SCREEN_HEIGHT - DOT_HEIGHT;
		if(yVel > 0)
			yVel = -(yVel - 50);
	}
}

void Dot::show()
{
	//Show the dot
	apply_surface( (int)x, (int)y, dot->getSurface(), screen );
}

void Dot::gravity()
{
	yVel += GRAVITY;
}

void Dot::friction()
{
	yVel *= FRICTION;
}

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
	Dot myDot;

	//Keeps track of time since last rendering
	Timer delta;

	//Initialize
	if( init() == false )
	{
		return 1;
	}

	//Load the files
	if( load_files() == false )
	{
		return 1;
	}
	
	Image* otherDot = new Image(*dot);
	//*otherDot = *dot;

	cout << dot << endl;
	cout << otherDot << endl;
	cout << dot->getSurface() << endl;
	cout << otherDot->getSurface() << endl;
	
	delete otherDot;
	/*dot = new Image();
	*dot = *otherDot;*/

	//Start delta timer
	delta.start();

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
		}

		//Handle events for the dot
		myDot.handle_input();

		int tmpTicks = delta.get_ticks();

		myDot.gravity();
		myDot.friction();

		//Move the dot
		myDot.move( delta.get_ticks() );

		//Restart delta timer
		delta.start();

		//Fill the screen white
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

		//Show the dot on the screen
		myDot.show();

		//Update the screen
		if( SDL_Flip( screen ) == -1 )
		{
			return 1;
		}

		//Cap the frame rate
	/*	if ( tmpTicks < 1000 / FRAMES_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - tmpTicks );
		}*/
	}

	//Clean up
	clean_up();

	return 0;
}
