//Traffic Simulator 2016

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "functions.h"
#include <fstream>
#include <vector>
//#include "TrafficLight.h"

using namespace std;

class Place
{
public:
	//Loads in the contents of Place.txt to the map vector
	Place();

	//Prints out the map after it's been loaded in
	void printMap();

	//Returns a given part of the map as an integer location.
	static int returnPlace(int x, int y);

	//Makes it significantly easier to create a static 2D vector
	typedef vector<vector<int>> world;
	static world map;
private:
	
};