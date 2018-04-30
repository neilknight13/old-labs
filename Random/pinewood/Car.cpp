#pragma once
#include "Car.h"
#include <iostream>
#include <string>
	/*
	*	getName()
	*
	*	Returns the name of this car.
	*/
	string Car::getName() const
	{
		cout << "in car GetName" << endl;
		return myName;	
	}

	/*
	*	getSpeed()
	*
	*	Returns the speed of this car.
	*/
	int Car::getSpeed() const
	{
		return mySpeed;
	}