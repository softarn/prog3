#ifndef DOT_H
#define DOT_H
#include "SDL/SDL.h"
#include "SpriteInput.h"

using namespace GameEng;

namespace Game {
    class Dot : public SpriteInput{
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
	    static const int DOT_WIDTH = 20;
	    static const int DOT_HEIGHT = 20;

	    static const float DOT_ACC_X = 0.4f;
	    static const float DOT_ACC_Y = 5;

	    static const int DOT_ACC_X_MAX = 6;
	    static const int DOT_ACC_Y_MAX = 7;

	    float GRAVITY;
	    float FRICTION;
    };
}
#endif
