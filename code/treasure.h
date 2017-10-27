#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "item.h"

class Treasure: public Item {
    int value;
    public:
        Treasure(int value):value(value) {
            setGraphic('G');
        }
        int getValue();
        void action(Character *c);
};
#endif
