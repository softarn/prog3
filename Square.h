#ifndef SQUARE_H
#define SQUARE_H

#include "SDL/SDL.h"
#include "Sprite.h"

using namespace GameEng;

namespace Game{
    class Square : public Sprite {
	public:
	    void draw() const;

	    void tick(){};

	    //Initializes the variables
	    Square(int x, int y, int w, int h);

	private:
	    int w;
	    int h;

	    SDL_Rect* rect;
    };
}
#endif
