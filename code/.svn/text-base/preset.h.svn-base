#ifndef __PRESET_H__
#define __PRESET_H__
#include <fstream>
#include "game.h"

class Preset: public Game {
    Cell *pc;
    std::ifstream *fi;
    public:
        Preset(std::string race, std::ifstream *i);
        void endTurn();
        void resetFloor();
        void loadFloor();
        ~Preset();
};

#endif
