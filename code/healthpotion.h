#ifndef __HEALTHPOTION_H__
#define __HEALTHPOTION_H__
#include "item.h"

class HealthPotion: public Item {
    int health;
    public:
        HealthPotion(int health): health(health) {
            setGraphic('P');
        }
        int getHealth();
        Player *action(Player *c);
};
#endif
