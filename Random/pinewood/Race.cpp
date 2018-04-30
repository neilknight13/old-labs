#include "Race.h"
#include "CarInterface.h"

	/*
	*	addCar(string)
	*
	*	Adds a new car to the collection of cars in the race. 
	*
	*	Return true if a new car was added; false otherwise.
	*   The info string should have the name, type, speed
	*/
	bool Race::addCar(string info)
	{
		stringstream ss(info);
		string name, type;
		int speed;
		
		if (ss >> name >> type >> speed) {
			cout << "addcar got " << name << " type " << type << "speed" << speed << endl;
			
			if (type == "R") {
				cout << "adding rocket");
				racecars.push_back(new Rocket(name, speed));
			}
			else if (type == "P") {
				cout << "adding panda");
				racecars.push_back(new Panda(name, speed));
			}
		}
		
	}

	/*
	*	removeCar(string)
	*
	*	Removes the car whose name is equal to the given name.  
	*
	*	Return true if a car is removed; false otherwise.
	*/
	bool Race::removeCar(string name)
	{
		
	}

	/*
	*	getCar(string)
	*
	*	Returns the memory address of a car whose name is equal to the given
	*	name.  Returns NULL if no fighter is found with the given name.
	*
	*	Return a memory address if a fighter is found; NULL otherwise.
	*/
	CarInterface* Race::getCar(string name)
	{
		
	}

	/*
	*	getSize()
	*
	*	Returns the number of cars in the race.
	*
	*	Return a non-negative integer.
	*/
	int Race::getSize() const
	{
	return racecars.size();	
	}