#pragma once
#include "CarInterface.h"
#include <iostream>
#include <string>

class Car: public CarInterface
{
protected:
	string myName;
	int mySpeed;
public:
	Car(string name, int speed) {
		myName=name; 
		mySpeed = speed;
	}
	virtual ~Car() {}

	/*
	*	getName()
	*
	*	Returns the name of this car.
	*/
	virtual string getName() const;

	/*
	*	getSpeed()
	*
	*	Returns the speed of this car.
	*/
	virtual int getSpeed() const;
};