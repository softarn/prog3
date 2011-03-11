#ifndef SQUARE_H
#define SQUARE_H

#include "SDL/SDL.h"
#include "Sprite.h"

using namespace GameEng;

namespace Game{
    class Square : public Sprite {
	public:
	    //Initializes the variables
	    Square(int x, int y, int w, int h);

	    const SDL_Rect& getRect() const;

	    void draw() const;

	    void tick(){};

	    virtual void randomizePos();

	    SDL_Rect rect;

	private:
	    int w;
	    int h;

    };
}
#endif
