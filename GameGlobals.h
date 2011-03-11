#ifndef GAMEGLOBALS_H
#define GAMEGLOBALS_H

#include "SDL/SDL.h"
#include <string>

namespace Game {

    struct GameGlobals{
    GameGlobals();
	~GameGlobals();

	int loosing_player_number;
	std::string player1;
	std::string player2;

	std::string endingMessage;
    };

    extern GameGlobals gamedata;
}

#endif
