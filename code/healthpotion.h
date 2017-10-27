#ifndef __HEALTHPOTION_H__
#define __HEALTHPOTION_H__
#include "item.h"

class HealthPotion: public Item {
    int health;
    public:
        HealthPotion(): health(10) {
            setGraphic('P');
        }
        int getHealth();
        void action(Character *c);
};
#endif
