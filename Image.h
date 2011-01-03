#ifndef IMAGE_H 
#define IMAGE_H

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
namespace Game {
    class Image{

	public:
	    Image();
	    Image( std::string path );
	    ~Image();
	    Image(const Image& other);
	    const Image& operator=(const Image& other);
	    SDL_Surface* getSurface() const;

	private:
	    SDL_Surface *load_image(std::string path);
	    SDL_Surface *img;

    };
}

#endif 
