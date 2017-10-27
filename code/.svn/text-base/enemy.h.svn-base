#ifndef __ENEMY_H__
#define __ENEMY_H__

//DON'T INCLUDE CCs
//#include "Character.cc"
#include "Character.h"
#include <string>

class Enemy: public Character {
	std::string action;
   public:
    Enemy() {
        en = true;
    }
	bool pathfind();
        void notifyReset() { };
	std::string getAction();
	bool setAction( std::string* combat );
};

#endif
