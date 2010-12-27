#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"

namespace Game {
    class Sprite{

	public:
	    Sprite();
	    Sprite( std::string path );
	    ~Sprite();

	    const Image& getImage() const;

	private:
	    Sprite(const Sprite& source);
	    const Sprite& operator=(const Sprite& source);

	    int x;
	    int y;
	    int xVel;
	    int yVel;

	    Image img;
    };
}

#endif
