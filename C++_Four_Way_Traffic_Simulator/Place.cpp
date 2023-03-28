//Traffic Simulator 2016

#include "Place.h"

Place::world Place::map;

//Loads in the contents of Place.txt to the map vector
Place::Place()
{
	//Sets the map vector to be a 25 by 80 array
	map.resize(30, vector<int>(85, 0));

	//Opens the Place.txt file and loads in the contents to map
	ifstream load("Place.txt");
	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < 80; i++)
		{
			load >> map[j][i];
		}
	}
}

//Returns a given part of the map as an int
int Place::returnPlace(int x, int y)
{
	return map[x][y];
}

//Prints out the map after it's been loaded in
void Place::printMap()
{
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			//Goes through and defines a colour based on the character then prints the 
			//character out at the given position
			if (map[y][x] == 219)
			{
				gotoxy((short)x, (short)y);
				coutchar(10, 219);
			}
			else if (map[y][x] == 177)
			{
				gotoxy((short)x, (short)y);
				coutchar(0, 177);
			}
			else if (map[y][x] == 186)
			{
				gotoxy((short)x, (short)y);
				coutchar(14, 186);
			}
			else if (map[y][x] == 205)
			{
				gotoxy((short)x, (short)y);
				coutchar(14, 205);
			}
			else if (map[y][x] == 0)
			{
				gotoxy((short)x, (short)y);
				coutcharbl(0, 0);
			}
			else
			{
				gotoxy((short)x, (short)y);
				coutchar(0, map[y][x]);
			}
		}
	}
}
