#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"

using namespace std;

class Fighter: public FighterInterface {
    public:
	Fighter(string myname, int mymaxHP, int mystrength, int myspeed, int mymagic) {
		name = myname; maxHP = mymaxHP; strength = mystrength; speed = myspeed; magic = mymagic; currentHP = mymaxHP;
	} 
	~Fighter() {}
	string getName() const; 
	virtual int getMaximumHP() const = 0;
	virtual int getCurrentHP() const = 0;
	virtual int getStrength() const = 0;
	virtual int getSpeed() const = 0;
	virtual int getMagic() const = 0;
	virtual int getDamage() = 0;
	virtual void takeDamage(int damage) = 0;
	virtual void reset() = 0;
	virtual void regenerate() = 0;
	virtual bool useAbility() = 0;
protected:
	string name;
	int maxHP;
	int strength;
	int speed;
	int magic;
	int currentHP;
};