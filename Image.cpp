#include "Image.h"
#include <iostream>

using namespace std;
namespace GameEng {
    Image::Image(){}

    Image::Image(std::string path){
	img = load_image(path);
    }

    Image::~Image(){
	if(img){
	    SDL_FreeSurface(img);
	}
    }

    Image::Image(const Image& other) : img(other.getSurface()) {
	img->refcount++;
    }

    const Image& Image::operator=(const Image& other){

	if (this != &other){
	    img = other.getSurface();
	    img->refcount++;
	}
	return *this;
    }

    SDL_Surface* Image::getSurface() const { return img; }

    SDL_Surface* Image::load_image( std::string path )
    {
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized surface that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load( path.c_str() );

	//If the image loaded
	if( loadedImage != NULL )
	{
	    //Create an optimized surface
	    optimizedImage = SDL_DisplayFormat( loadedImage );

	    //Free the old surface
	    SDL_FreeSurface( loadedImage );

	    //If the surface was optimized
	    if( optimizedImage != NULL )
	    {
		//Color key surface
		SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
	    }
	}

	//Return the optimized surface
	return optimizedImage;
    }
}
