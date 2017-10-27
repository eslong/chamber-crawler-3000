#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "GObject.h"
#include <string>

class Character: public GObject {
  protected:
    int hp, atk, def, gold;
    void setAttack(int a);
    void setHealth(int h);
    void setDefense(int d);
    bool en;
    virtual void notifyReset() { };
  public:
	int getHP();
	virtual int damage( int dmg );
	virtual std::string* attack( std::string direction );
	virtual bool move(std::string direction);
        void addHealth(int h);
	bool isEnemy();
	virtual int getAttack();
	virtual int getDefense();
	virtual int getGold();
};
#endif
