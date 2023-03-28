//Traffic Simulator 2016

#pragma once

#include "Vehicle.h"
#include "TrafficLight.h"

//Creates a class named Car that inherits from class Vehicle
class Car : public Vehicle
{
public:

	Car(); //Car object constructor and destructor.
	~Car();

	//Overrides the Vehicle function of the same name
	virtual void updateVehicle();

private:
	int dir; //Direction.
	int count; //Count of vehicles.
	int colour; //Color of vehicles.
	bool flag;
};