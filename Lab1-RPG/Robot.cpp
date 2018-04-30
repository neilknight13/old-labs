#include "Robot.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int Robot::getMaximumHP() const {
   return maxHP;
}
int Robot::getCurrentHP() const {
   return currentHP;
}
int Robot::getStrength() const {
   return strength;
}
int Robot::getSpeed() const {
   return speed;
}
int Robot::getMagic() const {
   return magic;
}
int Robot::getDamage() {
   int damageOutput;
   damageOutput = strength + bonusDamage;
   //cout << "bonus damage for " << name << " is " << bonusDamage << endl;
   bonusDamage = 0;
   //cout << "damage output for " << name << " is " << damageOutput << endl;
   return damageOutput;
}

void Robot::takeDamage(int damage) {
   if ((damage - (speed / 4)) < 1) {
      currentHP = currentHP - 1;
      //cout << "damage taken for " << name << " is 1" << endl;
   }
   else {
      currentHP = currentHP - (damage - speed / 4);
    //  cout << "damage taken for " << name << " is " << (damage - speed / 4) << endl;
   }
}

void Robot::reset() {
   currentHP = maxHP;
   currentEnergy = maxEnergy;
   bonusDamage = 0;
}
void Robot::regenerate() {
   int hitpointIncrease;
   if ((strength / 6) < 1) {
      hitpointIncrease = 1;
   }
   else {
      hitpointIncrease = ((strength) / 6);
   }
   currentHP = currentHP + hitpointIncrease;
   if (currentHP > maxHP) {
      currentHP = maxHP;
   }
}
bool Robot::useAbility() {
   double calculatedDamage = 0.0;
   if (currentEnergy >= ROBOT_ABILITY_COST) {
      double ratio = double(currentEnergy) / double(maxEnergy);
      calculatedDamage = (strength) * ratio * ratio * ratio * ratio;
      bonusDamage = calculatedDamage;
      currentEnergy = currentEnergy - ROBOT_ABILITY_COST;
      return true;

   }
   else {
      return false;
   }
}