#include "healthpotion.h"
#include "Character.h"
int HealthPotion::getHealth() {
    return health;
}

void HealthPotion::action(Character *c) {
    c->addHealth(health);
}
