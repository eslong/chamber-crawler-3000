#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Character.h"
#include <string>

class Game;

class Player: public Character {
	std::string race;
	int gold;
	Game* g;
   public:
	void notifyReset();
	int getAttack();
	int getDefence();
	int getGold();
	std::string getRace();
        void setGame(Game *game);
	void setRace( std::string race );
	void setGold( int g );
};

#endif
