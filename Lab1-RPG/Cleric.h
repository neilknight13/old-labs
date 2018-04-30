#pragma once
#include "Fighter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cleric : public Fighter {

public:
   Cleric(string clericName, int maxHP, int strength, int speed, int magic) : Fighter (clericName, maxHP, strength, speed, magic){
   	currentMana = magic * 5;
   	maxMana = magic * 5;
   }
   ~Cleric() {}
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
	int maxMana;
   int currentMana;
};