#ifndef __ENEMY_H__
#define __ENEMY_H__

//DON'T INCLUDE CCs
//#include "Character.cc"
#include "Character.h"

class Enemy: public Character {
   public:
    Enemy() {
        en = true;
    }
	bool pathfind();
    void notifyReset() { };
};

#endif
