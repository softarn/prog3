#include "Dot.h"
#include "Square.h"
#include "Globals.h"
#include "GameGlobals.h"


namespace Game{
    Dot::Dot(int x, int y, SDLKey l, SDLKey r, std::string dotname, int player, std::string playerName) : SpriteInput(dotname, x, y), FRICTION(0.9999f), player_number(player), player_name(playerName),
    GRAVITY(0.2f), leftKey(l), rightKey(r){
	    if(player_number == 1)
	    	gamedata.player1 = player_name;
	    else
	    	gamedata.player2 = player_name;

    }

    void Dot::draw() const{

	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(getImage().getSurface(), NULL, sys.screen, &offset);

    }

    void Dot::tick(){

	int dotBottom = y + DOT_HEIGHT;
	int dotTop = y;
	int dotRight = x + DOT_WIDTH;
	int dotLeft = x;

	//Get the keystates
	Uint8 *keystates = SDL_GetKeyState( NULL );

	//If left is pressed
	if( keystates[leftKey] && xVel > -200 ){
	    if(xVel > -DOT_ACC_X_MAX)
		xVel -= DOT_ACC_X;
	}

	//If right is pressed
	if( keystates[rightKey] && xVel < 200){
	    if(xVel < DOT_ACC_X_MAX)
		xVel += DOT_ACC_X;
	}

	gravity();
	friction();

	//Move dot
	x += xVel;

	//Make sure the dot is not outside the screen
	//to the left
	if( x < 0 ){
	    x = 0;
	    xVel = -xVel;

	}

	//Make sure the dot is not outside the screen
	//to the right
	else if( dotRight > sys.SCREEN_WIDTH ){
	    x = sys.SCREEN_WIDTH - DOT_WIDTH;
	    xVel = -xVel;

	}

	//Move dot
	y += yVel;

	//Make sure the dot is not outside the screen
	//to the top
	if( dotTop < 0 ){
	    y = 0;
	    yVel = -yVel;

	}
	//Make sure the dot is not outside the screen
	//or bottom
	
	else if( dotBottom > sys.SCREEN_HEIGHT ){
	    sys.run = false;
	    gamedata.loosing_player_number = player_number;
	}
    }

    void Dot::handle_input(SDL_Event& event){
/*	//If a key was pressed
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
*/
    }

    void Dot::gravity(){
	yVel += GRAVITY;
    }

    void Dot::friction(){
	yVel *= FRICTION;
    }

    bool Dot::collided(SDL_Rect target) const {
	int rightT = target.x + target.w;
	int leftT = target.x;
	int topT = target.y;
	int bottomT = target.y + target.h;

	if(rightT < x){
	    return false;
	}

	if(leftT > x + DOT_WIDTH){
	    return false;
	}

	if(topT > y + DOT_HEIGHT){
	    return false;
	}

	if(bottomT + DOT_HEIGHT/2 < y){
	    return false;
	}
	return true;
    }

    void Dot::collision(std::vector<Sprite*> comps){
	for(unsigned int i=0; i < comps.size(); i++) {
	    Square *square = dynamic_cast<Square*>(comps[i]);
	    if(square){
		if(collided(square->getRect())){
    		    if(yVel > 0){
			yVel = -yVel;
		    }
		    if(yVel > -8){
			yVel = -8;
		    }
		    square->randomizePos();
		}
	    }
	}
    }
}
