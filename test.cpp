//The headers
#include "GameEngine.h"
#include "Dot.h"
#include "Square.h"
#include "MovingSquare.h"

//using namespace std;
using namespace GameEng;
using namespace Game;

//The frame rate
const int FRAMES_PER_SECOND = 90;

//The event structure
SDL_Event event;

int main( int argc, char* args[] )
{
	std::string player_one_name = "Player One";
	std::string player_two_name = "Player Two";
	int number_of_players = 0;

	// TODO: DAMN, is it supposed to be this fucked up to compare two effin strings?
	   for(int i = 0; i < argc; i++) {
		   bool p1equal = (strcmp(args[i], "-p1name") == 0);
		   if(p1equal) {
			   player_one_name = std::string(args[++i]);
		   }
		   bool p2equal = (strcmp(args[i], "-p2name") == 0);
		   if(p2equal) {
			   player_two_name = std::string(args[++i]);
		   }

		   bool npequal = (strcmp(args[i], "-nplayers") == 0);
		   if(npequal) {
			   number_of_players = atoi(args[++i]);
		   }

	   }

    GameEngine ge(FRAMES_PER_SECOND);

    Dot *dot = new Dot(100, 50, SDLK_LEFT, SDLK_RIGHT, "dot.bmp", 1, player_one_name);
    Dot *dot2 = new Dot(400, 50, SDLK_a, SDLK_d, "dot_blue.bmp", 2, player_two_name);
    Square *platform = new Square(10, 500, 100, 10);
    Square *platform1 = new Square(190, 500, 100, 10);
    Square *platform2 = new Square(490, 500, 100, 10);
    Square *platform3 = new Square(300, 500, 100, 10);
    MovingSquare *square = new MovingSquare(0, sys.SCREEN_HEIGHT - 15, 50, 10);


    ge.add(platform1);
    ge.add(platform2);
    ge.add(platform3);
    ge.add(platform);
    ge.add(square);

    if(number_of_players == 1)
        ge.add(dot);
    else {
        ge.add(dot2);
        ge.add(dot);
    }
    ge.run();

    //Clean up
    return 0;
}
