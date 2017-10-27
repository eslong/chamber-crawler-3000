#ifndef __GAME_H__
#define __GAME_H__

#include "player.h"
#include "floor.h"
#include "textdisplay.h"
#include <string>

class Game {
    protected:
	Player* player;
	Floor* floor;
	int floorCount;
	std::string action;
   public:
	Game( std::string );
	virtual ~Game();
	void gameLoop();
	void endTurn();
	virtual void resetFloor();
};

#endif

