//Traffic Simulator 2016

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "functions.h"
#include "Vehicle.h"
#include <fstream>
#include <vector>

using namespace std;

//Creats a class named Truck that inherits from class Vehicle
class Truck : public Vehicle
{
public:

	Truck(); //Truck constructors and deconstructors.
	~Truck();

	//Overrides the Vehicle function of the same name
	virtual void updateVehicle();

private:
	int dir; //Vehicle direction.
	int count; //Vehicle count.
	int colour; //Vehicle color.
	bool flag;
};