#ifndef GAMEENGINE_H
#define GAMEENGINE_H

namespace Game {
	class GameEngine {

		public:
			GameEngine(int sw, int sh, int sbpp, int sfps, std::string stitle);
			~GameEngine();
			int run();
			void add(int* spr);

		private:
			GameEngine(const GameEngine& other);
			const GameEngine& operator=(const GameEngine& other);

			bool init();

			int screen_w;
			int screen_h;
			int screen_bpp;
			int fps;

			SDL_Surface *screen;

			std::string title;

			std::vector<int*> comps;
			Uint32 bgColor;

	}
}
#endif
