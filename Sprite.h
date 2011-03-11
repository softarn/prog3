#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"
#include <string>

namespace GameEng {
    class Sprite{

	public:
	    virtual void draw() const = 0;
	    virtual void tick() = 0;
	    const Image& getImage() const;
	    

	protected:
	    Sprite(std::string path, int xx, int yy);

	    int x;
	    int y;
	    float xVel;
	    float yVel;

	private:
	    Sprite(const Sprite& source);
	    const Sprite& operator=(const Sprite& source);

	    Image img;
    };
}

#endif
