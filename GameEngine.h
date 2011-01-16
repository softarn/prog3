#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Sprite.h"
#include <vector>
#include "SDL/SDL.h"

namespace GameEng {

    class GameEngine {
	public:
	    GameEngine(int fps = 90) : FRAMES_PER_SECOND(fps){};
	    ~GameEngine();
	    void add(Sprite* spr);
	    int run();
	private:
	    GameEngine(const GameEngine& other);
	    const GameEngine& operator=(const GameEngine& other);

	    int screen_w;
	    int screen_h;
	    int screen_bpp;
	    int fps;
	    int FRAMES_PER_SECOND;

	    SDL_Surface *screen;

	    std::string title;

	    std::vector<Sprite*> comps;
	    Uint32 bgColor;
    };

}

#endif
