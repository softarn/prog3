#ifndef DOT_H
#define DOT_H
#include "SDL/SDL.h"
#include "SpriteInput.h"

using namespace GameEng;

namespace Game {
    class Dot : public SpriteInput{
	public:
	    //Initializes the variables
	    Dot(int x, int y, SDLKey l, SDLKey r, std::string dotname);

	    //Not used
	    void handle_input(SDL_Event& event);

	    //Moves the dot
	    void tick();

	    void draw() const;
	    
	    void gravity();

	    void friction();

	    void collision(std::vector<Sprite*> comps);

	    bool collided(SDL_Rect target) const;

	private:
	    static const int DOT_WIDTH = 20;
	    static const int DOT_HEIGHT = 20;

	    static const float DOT_ACC_X = 0.4f;
	    static const float DOT_ACC_Y = 10;

	    static const int DOT_ACC_X_MAX = 7;
	    static const int DOT_ACC_Y_MAX = 18;

	    float GRAVITY;
	    float FRICTION;

	    SDLKey leftKey, rightKey;
    };
}
#endif
