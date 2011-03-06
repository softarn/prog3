#include "Square.h"
#include "Globals.h"

namespace Game{
    Square::Square(int xx, int yy, int ww, int hh) : 
	Sprite("dot.bmp", xx, yy), w(ww), h(hh){
	    rect.x = x;
	    rect.y = y;
	    rect.w = w;
	    rect.h = h;
	}

    const SDL_Rect& Square::getRect() const{
	return rect;
    }

    void Square::draw() const{
	SDL_Rect* tmpRect = new SDL_Rect(rect);
	SDL_FillRect( sys.screen, tmpRect, SDL_MapRGB( sys.screen->format, 0x77, 0x77, 0x77 ) );
    }
}
