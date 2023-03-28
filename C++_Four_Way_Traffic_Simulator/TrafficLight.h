//Traffic Simulator 2016

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "functions.h"
#include "Place.h"
#include <vector>

using namespace std;

class TrafficLight
{
public:
	//Loads the col array with the code for red, yellow, and green
	TrafficLight(int, int);

	//Prints the lights out into the console
	void printLights();

	//Used for setting the North and South light colours
	void NSGreen();
	void NSYellow();
	void NSRed();

	//Used for setting the East and West light colours
	void EWGreen();
	void EWYellow();
	void EWRed();
	
	//Returns the currently set colour of either the North and South or the East and West lights
	char getNSCol() const;
	char getEWCol() const;

	//Used for the update timer for timing the lights
	int updateNSLights(int);
	int updateEWLights(int);

	//Used for placing and removing the vehicle block
	void NSblock();
	void NSunBlock();
	void EWblock();
	void EWunBlock();

	//Creates a 2D vector "on top" of the map 2D vector to handle vehicle movement
	typedef vector<vector<int> > veh;
	static veh vehMap;
	static int getPlace(int,int);
	static void setPlace(int, int, int);

private:

	int col[3];
	int NSTimeG, NSTimeY, NSTimeR;
	int EWTimeG, EWTimeY, EWTimeR;
	int NScnt, EWcnt;
	char NSCol;
	char EWCol;
	
	//Used to set the North and South or the East and West lights off
	void NSOff();
	void EWOff();
};