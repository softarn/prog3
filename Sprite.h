#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"
#include <string>

namespace Game {
    class Sprite{

	public:
	    Sprite();
	    Sprite(std::string path, int xx, int yy);
	    ~Sprite();
    	    virtual void handle_input(SDL_Event& event) = 0;

	    virtual void draw() const = 0;
	    virtual void tick() = 0;
	    const Image& getImage() const;
	    
	    int x;
	    int y;
	    float xVel;
	    float yVel;

	protected:
	    Sprite( std::string path );
	    

	private:
	    Sprite(const Sprite& source);
	    const Sprite& operator=(const Sprite& source);

	    Image img;
    };
}

#endif
