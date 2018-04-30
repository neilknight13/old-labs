#pragma once
#include "Fighter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robot : public Fighter {

public:
   Robot(string robotName, int maxHP, int strength, int speed, int magic) : Fighter (robotName, maxHP, strength, speed, magic){
      currentEnergy = magic * 2;
      bonusDamage = 0;
      maxEnergy = magic * 2;
   }
   ~Robot() {}
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
   int maxEnergy;
   int currentEnergy;
   int bonusDamage;
};