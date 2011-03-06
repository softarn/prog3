#include "Square.h"
#include "Globals.h"

namespace Game{
    Square::Square(int xx, int yy, int ww, int hh) : 
	Sprite(NULL, xx, yy), w(ww), h(hh){
	    rect->x = x;
	    rect->y = y;
	    rect->w = w;
	    rect->h = h;
	}

    void Square::draw() const{
	SDL_FillRect( sys.screen, rect, SDL_MapRGB( sys.screen->format, 0x77, 0x77, 0x77 ) );
    }
}
    
