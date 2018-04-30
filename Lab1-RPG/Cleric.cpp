#include "Cleric.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Cleric::getMaximumHP() const {
   return maxHP;
}

int Cleric::getCurrentHP() const {
   return currentHP;
}

int Cleric::getStrength() const {
   return strength;
}

int Cleric::getSpeed() const {
   return speed;
}

int Cleric::getMagic() const {
   return magic;
}
int Cleric::getDamage() {
   return magic;
}
void Cleric::takeDamage(int damage) {
   int damageTaken = 0;
   damageTaken = damage - (speed / 4);
   if (damageTaken < 1) {
      damageTaken = 1;
   }
   currentHP = currentHP - damageTaken;
}

void Cleric::reset() {
   currentHP = maxHP;
   currentMana = maxMana;
}

void Cleric::regenerate() {
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
   int manaIncrease;
   if ((magic /5) < 1) {
      manaIncrease = 1;
   }
   else {
      manaIncrease = magic / 5;
   }
   currentMana = currentMana + manaIncrease;
   if (currentMana > magic * 5) {
      currentMana = magic * 5;
   }
}
bool Cleric::useAbility() {
   if (currentMana >= CLERIC_ABILITY_COST) {
      currentMana = currentMana - CLERIC_ABILITY_COST;
      if ((magic / 3) < 1) {
         currentHP = currentHP + 1;
      }
      else {
         currentHP = currentHP + (magic / 3);
      }
      if (currentHP > maxHP) {
         currentHP = maxHP;
      }
      return true;
   }
   else {
      return false;
   }
}
