#pragma once
#include "Fighter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Archer : public Fighter {

public:
   Archer(string archerName, int maxHP, int strength, int speed, int magic) : Fighter (archerName, maxHP, strength, speed, magic){
   	boostedSpeed = speed;
   }
   ~Archer() {}
   int getMaximumHP() const;
   int getCurrentHP() const;
	int getStrength() const;
	int getSpeed() const;
	int getMagic() const;
	int getDamage();
	void takeDamage(int damage);
	void reset();
	void regenerate();
	bool useAbility();
private:
   int boostedSpeed;
};