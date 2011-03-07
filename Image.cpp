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

    SDL_Surface* Image::load_image( std::string path ){
	SDL_Surface* loadImg = NULL;
	SDL_Surface* opImg = NULL;

	loadImg = IMG_Load( path.c_str() );

	if(loadImg != NULL){
	    
	    opImg = SDL_DisplayFormat(loadImg);
	    SDL_FreeSurface(loadImg);

	    if(opImg != NULL){
		Uint32 transp = *(Uint32*)opImg->pixels;
		SDL_SetColorKey( opImg, SDL_SRCCOLORKEY, transp );
	    }
	}

	return opImg;
    }
}
