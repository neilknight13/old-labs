#include "Archer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Archer::getMaximumHP() const {
   return maxHP;
}

int Archer::getCurrentHP() const {
   return currentHP;
}

int Archer::getStrength() const {
   return strength;
}

int Archer::getSpeed() const {
   return boostedSpeed;
}

int Archer::getMagic() const {
   return magic;
}

int Archer::getDamage() {
   return boostedSpeed;
}
void Archer::takeDamage(int damage) {
   int damageTaken = 0;
   damageTaken = damage - (boostedSpeed / 4);
   if (damageTaken < 1) {
      damageTaken = 1;
   }
   currentHP = currentHP - damageTaken;
}

void Archer::reset() {
   currentHP = maxHP;
   boostedSpeed = speed;
}
void Archer::regenerate() {
   int hitpointIncrease;
   if ((strength / 6) < 1) {
      hitpointIncrease = 1;
   }
   else {
      hitpointIncrease = strength / 6;
   }
   currentHP = currentHP + hitpointIncrease;
   if (currentHP > maxHP) {
      currentHP = maxHP;
   }
}
bool Archer::useAbility() {
   boostedSpeed = boostedSpeed + 1;
   return true;
}