#include "SDL/SDL.h"
#include "GameGlobals.h"

namespace Game {

	GameGlobals gamedata;

	GameGlobals::GameGlobals() : endingMessage("Player that won the game: "){

    }

	GameGlobals::~GameGlobals(){
    }
}
