#include "Square.h"

namespace GameEng{
    Square::Square(int xx, int yy, int ww, int hh) : 
	x(xx), y(yy), w(ww), h(hh){
	    rect.x = x;
	    rect.y = y;
	    rect.w = w;
	    rect.h = h;
	}

    void Square::draw() const{
	SDL_FillRect( sys.screen, &rect, SDL_MapRGB( screen->format, 0x77, 0x77, 0x77 ) );
    }
}
    
