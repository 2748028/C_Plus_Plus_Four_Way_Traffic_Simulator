//Traffic Simulator 2016

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "functions.h"
#include <fstream>
#include "Place.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include <string>

using namespace std;

//Main function - Does a lot of fun stuff
int main()
{
	//Generates a seed for the randome number generator.
	srand(time(0));

	//Asks users to enter North South light time, East West light time, how many cars they want, and probability of car appearing
	int NSTimer, EWTimer, carCount, probChance;

	cout << "Enter the timer for the North/South green lights: " << endl;
	cout << "A value between 10 - 30 is recommended. " << endl;

	try // Check to see if the value entered for the N/S timer is not equal to or below 0.
	{
		cin >> NSTimer;
		if (NSTimer <= 0)
		{
			throw 1;
		}
	}
	catch (int x)
	{
		cout << "Integers below or equal to the value of 0 cannot be entered! " << endl;
		cout << "Please restart the program. " << endl;

		system("pause");
		return 0;
	}

	cout << "Enter the timer for the East/West green lights: " << endl;
	cout << "A value between 10 - 30 is recommended. " << endl;

	try // Check to see if the value entered for the E/W timer is not equal to or below 0.
	{
		cin >> EWTimer;
		if (EWTimer <= 0)
		{
			throw 1;
		}
	}
	catch (int x)
	{
		cout << "Integers below or equal to the value of 0 cannot be entered! " << endl;
		cout << "Please restart the program. " << endl;

		system("pause");
		return 0;
	}

	cout << "Enter the amount of vehicles you want to simulate: " << endl;

	try // Check to see if the value entered for the vehicle pool is not equal to or below 0.
	{
		cin >> carCount;
		if (carCount <= 0)
		{
			throw 1;
		}
	}
	catch (int x)
	{
		cout << "Integers below or equal to the value of 0 cannot be entered! " << endl;
		cout << "Please restart the program. " << endl;

		system("pause");
		return 0;
	}

	cout << "Enter the probabilty of a new car entering the intersection (1/n): " << endl;
	cout << "A value equal to or above (30) is recommended. " << endl;

	try // Check to see if the value entered for the probability calculator is not equal to or below 0.
	{
		cin >> probChance;
		if (probChance <= 0)
		{
			throw 1;
		}
	}
	catch (int x)
	{
		cout << "Integers below or equal to the value of 0 cannot be entered! " << endl;
		cout << "Please restart the program. " << endl;

		system("pause");
		return 0;
	}

	//Creates the map
	Place a;
	//Loads the user's input into the Traffic Lights
	TrafficLight l(NSTimer, EWTimer);

	//Prints out the map and traffic lights
	a.printMap();
	l.printLights();

	//Creates a vector for vehicles locations on the map.
	vector<Vehicle*> veh;

	//Loads the vector up with Cars and Trunk at a 1:4 ratio because trucks overload the map.
	int e;
	for (int k = 0; k < carCount; k++)
	{
		e = rand();

		if ((e % 4) == 1)
			veh.push_back(new Car());
		else if ((e % 4) == 2)
			veh.push_back(new Car());
		else if ((e % 4) == 3)
			veh.push_back(new Car());
		else if ((e % 4) == 0)
			veh.push_back(new Truck());

	}

	//Initializes a counter for the lights and vehicle updater
	int NScount = 0;
	int EWcount = 0;
	int i = 1;
	int w = 0;

	//While loop that operates everything 
	while (true){
		
		//Lights get updated and return their counter back for reuse
		NScount = l.updateNSLights(NScount);
		EWcount = l.updateEWLights(EWcount);
		NScount++;
		EWcount++;

		//Calls the updateVehicle function for the Car and Truck class
		for (w = 0; w < i; w++)
		{
			veh[w]->updateVehicle();
		}

		//Introduces new vehicles into the program based off user input
		if ((rand() % probChance) == 1 && i != (carCount))
		{
			i++;
		}

		//Outputs statistics to the window below the simulation
		gotoxy(0, 27);
		coutcharbl(15, 45);
		cout << " Success from West: " << Vehicle::westCount;
		gotoxy(0, 28);
		coutcharbl(15, 45);
		cout << " Success from East: " << Vehicle::eastCount;
		gotoxy(0, 29);
		coutcharbl(15, 45);
		cout << " Success from North: " << Vehicle::northCount;
		gotoxy(0, 30);
		coutcharbl(15, 45);
		cout << " Success from South: " << Vehicle::southCount;

		Sleep(100); //Pauses the loop for a short period for viewing pleasure.
	}

	//Base case to ensure the program halts safely if it breaks out of the while loop.
	gotoxy(0, 25);
	system("pause");
	return 0;
}
