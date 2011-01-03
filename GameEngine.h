#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Sprite.h"
#include <vector>
#include "SDL/SDL.h"
namespace Game {
	class GameEngine {
		public:
			GameEngine();
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
			static const int FRAMES_PER_SECOND = 80;

			SDL_Surface *screen;

			std::string title;

			std::vector<Sprite*> comps;
			Uint32 bgColor;
	};
}
#endif
