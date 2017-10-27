#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Character.h"
#include <string>
class Game;

class Player: public Character {
	std::string race;
	int gold;
    Game *g;
    void notifyReset();
   public:
	//Player();
	//~Player();
	int getAttack();
	int getDefence();
	int getGold();
	std::string getRace();
	void setRace( std::string );
	void setGold( int n );
    void setGame(Game *game);
};

#endif	
