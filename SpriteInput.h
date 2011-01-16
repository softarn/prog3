#ifndef SPRITEINPUT_H
#define SPRITEINPUT_H

#include "Sprite.h"

namespace GameEng{
    class SpriteInput : public Sprite{
	public:
	    virtual void handle_input(SDL_Event& event) = 0;
	    void draw() const = 0;
	    void tick() = 0;
	protected:
	    SpriteInput(std::string path, int xx, int yy) : Sprite (path, xx, yy){};
    };
}

#endif
