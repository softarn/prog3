#ifndef GAMEENGINE_H
#define GAMEENGINE_H

namespace Game {
	class Sprite{

		public:
			Sprite();
			~Sprite();

		private:
			Sprite(const Sprite& other);
			const Sprite& operator=(const Sprite& other);

			int x;
			int y;
			int xVel;
			int yVel;

			Image img;
	}
}
#endif
