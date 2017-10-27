#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Character.h"
#include <string>
class Game;

class Player: public Character {
	std::string race;
	Game* g;
   public:
	void notifyReset();
	int getDefence();
	std::string getRace();
        void setGame(Game *game);
	void setRace( std::string race );
	void setGold( int g );
        Player *useItem(std::string direction);
};

#endif
