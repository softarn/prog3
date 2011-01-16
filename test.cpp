//The headers
#include "GameEngine.h"
#include "Dot.h"

//using namespace std;
using namespace GameEng;
using namespace Game;

//The frame rate
const int FRAMES_PER_SECOND = 80;

//The event structure
SDL_Event event;

int main( int argc, char* args[] )
{
    GameEngine ge;

    //The dot that will be used
    Dot *myDot = new Dot(100, 200);

    ge.add(myDot);
    ge.run();

    //Clean up
    return 0;
}
