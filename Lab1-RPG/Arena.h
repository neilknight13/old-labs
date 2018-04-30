#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ArenaInterface.h"
#include "FighterInterface.h"
#include "Fighter.h"
#include "Cleric.h"
#include "Archer.h"
#include "Robot.h"

using namespace std;

class Arena : public ArenaInterface {
	private:
	vector<Fighter*> fighterVector;
	
	public:
	Arena() {}
	~Arena() {}
	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize() const;
};

