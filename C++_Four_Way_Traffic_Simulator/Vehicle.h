//Traffic Simulator 2016

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "functions.h"
#include <vector>

using namespace std;

//Pure virtual class for Car and truck to be derived from
class Vehicle
{
public:
	//Contains the update function and four static variables for completion counting
	virtual void updateVehicle() = 0; 
	static int westCount;
	static int eastCount;
	static int northCount;
	static int southCount;
};