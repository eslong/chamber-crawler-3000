#ifndef __GAME_H__
#define __GAME_H__

#include "player.h"
#include "floor.h"
#include "textdisplay.h"
#include <string>

class Game {
	Player* player;
	Floor* floor;
	int floorCount;
	int playerDmg, enemyDmg;
	std::string action;
   public:
	Game( std::string race );
	~Game();
	void gameLoop();
	void endTurn();
    void resetFloor();
};

#endif

