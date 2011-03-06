#include "Dot.h"
#include "Globals.h"
#include <iostream>

using namespace std;

namespace Game{
    Dot::Dot(int x, int y) : SpriteInput("dot.bmp", x, y), FRICTION(0.9999f),
	GRAVITY(0.2f){}

    void Dot::draw() const{

	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(getImage().getSurface(), NULL, sys.screen, &offset);

    }

    void Dot::tick(){
	
	//Get the keystates
	Uint8 *keystates = SDL_GetKeyState( NULL );

	//If left is pressed
	if( keystates[ SDLK_LEFT ] && xVel > -200 )
	{
	    if(xVel > -DOT_ACC_X_MAX)
		xVel -= DOT_ACC_X;
	}

	//If right is pressed
	if( keystates[ SDLK_RIGHT ] && xVel < 200)
	{
	    if(xVel < DOT_ACC_X_MAX)
		xVel += DOT_ACC_X;
	}

	gravity();
	friction();
	
	//Move the dot left or right
	x += xVel;

	//If the dot went too far to the left
	if( x < 0 )
	{
		//Move back
		x = 0;
		xVel = -(xVel * 0.70f);
	}
	//or the right
	else if( x + DOT_WIDTH > sys.SCREEN_WIDTH )
	{
		//Move back
		x = sys.SCREEN_WIDTH - DOT_WIDTH;
		xVel = -(xVel * 0.70f);
	}

	//Move the dot up or down
	y += yVel;

	//If the dot went too far up
	if( y < 0 )
	{
		//Move back
		y = 0;
		yVel = -yVel;
	}
	//or down
	else if( y + DOT_HEIGHT > sys.SCREEN_HEIGHT )
	{
		//Move back
		y = sys.SCREEN_HEIGHT - DOT_HEIGHT;

		if(yVel > 0)
			yVel = -(yVel - 4);
	}
    }
    
    void Dot::handle_input(SDL_Event& event)
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
		    if( y + DOT_HEIGHT >= sys.SCREEN_HEIGHT - 5 && yVel > -250 ){
			int direction;
			if(yVel > 0)
			    direction = 1;
			else
			    direction = -1;
			yVel = DOT_ACC_Y * direction;

		    } break;
	    }
	}

    }

    void Dot::gravity()
    {
	yVel += GRAVITY;
    }

    void Dot::friction()
    {
	yVel *= FRICTION;
    }
}
