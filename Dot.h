#ifndef DOT_H
#define DOT_H
#include "SDL/SDL.h"
#include "Sprite.h"

using namespace Game;

namespace Game {
    class Dot : public Sprite{
	public:
	    //Initializes the variables
	    Dot(int x, int y);

	    //Takes key presses and adjusts the dot's velocity
	    void handle_input(SDL_Event& event);

	    //Moves the dot
	    void tick();

	    //Shows the dot on the screen
	    void draw() const;

	    void gravity();

	    void friction();

	private:
	    int DOT_WIDTH;
	    int DOT_HEIGHT;

	    int DOT_ACC_X;
	    int DOT_ACC_Y;

	    float GRAVITY;
	    float FRICTION;
    };
}
#endif
