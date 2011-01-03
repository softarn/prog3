#include "Sprite.h"
#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

namespace Game {
    Sprite::Sprite(){}
    Sprite::Sprite( std::string path, int xx, int yy ) : img(path), x(xx), y(yy), xVel(0), yVel(0){}
    Sprite::~Sprite(){}

    void Sprite::handle_input(SDL_Event& event)
    {
	}

    const Image& Sprite::getImage() const {
	return img;
    }

    Sprite::Sprite(const Sprite& source) : img(source.getImage()){}

    const Sprite& Sprite::operator=(const Sprite& source){
	if (this != &source){
	    img = source.getImage();
	}
	return *this;
    }
}
