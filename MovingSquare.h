#include "Globals.h"

namespace Game {
	class MovingSquare : public Square {
		public:
		MovingSquare(int x, int y, int w, int h) :
			Square(x,y,w,h) {};

		void tick() {
			if(rect.x > sys.SCREEN_WIDTH)
			rect.x = 0 - rect.w;
			rect.x += 4;
		};

		void randomizePos() {
		};
	};

}
