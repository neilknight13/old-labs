

#include <iostream>
#include <string>
#include <vector>
#include "Arena.h"
#include "FighterInterface.h"

using namespace std;

	bool Arena::addFighter(string info) {
       stringstream ss(info);
       string name, type;
       int maxHP, strength, speed, magic;
       char userInput;
		
	   if (ss >> name >> type >> maxHP >> strength >> speed >> magic) {
	   	userInput = ss.get();
	   	if (isspace(userInput)) {
	   		return false;
	   	}
	   	ss.putback(userInput);
	   	 bool fighterFound = false;
	       for (Fighter* fp : fighterVector) {
	          if (fp->getName() == name) {
	             fighterFound = true;
	             return false;
	    	  }
		   }
		   if (type == "R" && fighterFound == false) { 
			   fighterVector.push_back(new Robot(name, maxHP, strength, speed, magic));
		   }
		   else if (type == "A" && fighterFound == false) { 
			   fighterVector.push_back(new Archer(name, maxHP, strength, speed, magic));
		   }
		   else if (type == "C" && fighterFound == false) { 
		      fighterVector.push_back(new Cleric(name, maxHP, strength, speed, magic));
		   }
		else {
			return false; //not a valid type of fighter
		}
		return true;
	}
	return false; //invalid input, not enough tokens or wrong input type
	}
	
	bool Arena::removeFighter(string name) { 
	   for (int i = 0; i < fighterVector.size(); i++) {
		   if (fighterVector.at(i)->getName() == name) {
			   fighterVector.erase(fighterVector.begin() + i);
			   return true;
		   }
	   }
	   return false;
	}

	FighterInterface* Arena::getFighter(string name) { 
	   stringstream ss;
	   for (Fighter* fp : fighterVector) {
	      if (fp->getName() == name) {
	         return fp;
	      }
	   }
	   return NULL;
	}

	int Arena::getSize() const {
	   return fighterVector.size();
	}

