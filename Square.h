#ifndef SQUARE_H
#define SQUARE_H
#include "SDL/SDL.h"

namespace GameEng {
    class Square {
	public:
	    //Initializes the variables
	    Square(int x, int y, int w, int h);

	    //Shows the squre on the screen
	    void draw() const;

	private:
	    int x;
	    int y;
	    int w;
	    int h;

	    SDL_Rect rect;
    };
}
#endif
