//The headers
#include "GameEngine.h"
#include "Dot.h"
#include "Square.h"

//using namespace std;
using namespace GameEng;
using namespace Game;

//The frame rate
const int FRAMES_PER_SECOND = 90;

//The event structure
SDL_Event event;

int main( int argc, char* args[] )
{
    GameEngine ge(FRAMES_PER_SECOND);

    //The dot that will be used
    Dot *myDot = new Dot(100, 50);
    Square *platform = new Square(90, 500, 100, 10);
    Square *platform1 = new Square(190, 500, 100, 10);
    Square *platform2 = new Square(490, 500, 100, 10);

    ge.add(platform1);
    ge.add(platform2);
    ge.add(platform);
    ge.add(myDot);
    ge.run();

    //Clean up
    return 0;
}
