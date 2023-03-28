//Traffic Simulator 2016

#include "Truck.h"
#include "TrafficLight.h"

Truck::Truck()
{
	/* Reference for what number equate to what direction
	0 - West
	1 - East
	2 - North
	3 - South
	*/

	//Randomly assigns a colour to the Truck
	colour = rand() % 16;
	if (colour == 8)
		colour = 15;

	//Randomly assigns a direction to the Truck
	dir = rand() % 4;
	if (dir == 0)
		count = 9;
	else if (dir == 1)
		count = 79;
	else if (dir == 2)
		count = 4;
	else if (dir == 3)
		count = 25;

	flag = false;
}

//This kills the truck.
Truck::~Truck()
{
	delete this;
}

//Updates the Truck movement
void Truck::updateVehicle()
{
	//Affects Trucks coming from the West
	if (dir == 0 && count != 81)
	{
		//Checks to make sure there is nothing blocking the way
		if (TrafficLight::getPlace(count + 1, 15) != 219 && TrafficLight::getPlace(count + 1, 14) != 219)
		{
			if (count < 80)
			{
				//Prints out the Trucks and logically sets them
				for (int i = 0; i < 5; i++)
				{
					gotoxy(count-i, 14);
					coutchar(colour, 219);
					TrafficLight::setPlace(count-1, 14, 219);
				}
				count++;
			}
			//Ensures that the Truck is printed onscreen
			if (count > 2)
			{
				gotoxy(count - 8, 14);
				coutchar(0, Place::returnPlace(14, count - 8));
				TrafficLight::setPlace(count - 8, 14, 255);
			}
				//Once the Truck reaches the end then erase it and logically remove it
				if (count == 80)
				{
					for (int i = 0; i < 8; i++)
					{
						gotoxy(80-i, 14);
						coutchar(0, Place::returnPlace(14, 80-i));
						TrafficLight::setPlace(80-i, 14, 255);

						//Increments the West counter
						if (flag == false){
							Vehicle::westCount++;
							flag = true;
						}
					}
				}
		}
	}

	//Handles Trucks coming from the East
	else if (dir == 1 && count != 3)
	{
		//Ensures there's nothing in front of the Truck
		if (TrafficLight::getPlace(count - 4, 9) != 219 && TrafficLight::getPlace(count - 4, 10) != 219)
		{
			if (count > 3)
			{
				//Prints out the Truck
				for (int i = 0; i < 4; i++)
				{
					gotoxy(count - i, 10);
					coutchar(colour, 219);
					TrafficLight::setPlace(count - i, 10, 219);
				}
			}
			//Ensures the Truck doesn't print off the console
			if (count >= 3)
			{
				gotoxy(count + 5, 10);
				coutchar(0, Place::returnPlace(10, count + 5));
				TrafficLight::setPlace(count + 5, 10, 255);
			}
			//Erases the Truck once it reaches the end
			if (count <= 4)
			{
				for (int i = 1; i < 9; i++)
				{
					gotoxy(i, 10);
					coutchar(0, Place::returnPlace(10, i));
					TrafficLight::setPlace(i, 10, 255);

					//Increments the East counter
					if (flag == false){
						Vehicle::eastCount++;
						flag = true;
					}
				}
			}

			if (count >= 4)
				count--;
		}
	}
	//Handles Trucks coming from the North
	else if (dir == 2 && count != 25)
	{
		//Ensures there's nothing in front of the Truck
		if (TrafficLight::getPlace(35, count + 1) != 219 && TrafficLight::getPlace(36, count + 1) != 219)
		{
			if (count < 25)
			{
				//Prints out the Truck
				for (int i = 0; i < 4; i++)
				{
					gotoxy(36, count-i);
					coutchar(colour, 219);
					TrafficLight::setPlace(36, count-i, 219);
				}
				count++;
			}

			//Ensures the Truck doesn't get printed off the screen
			if (count > 2)
			{
				gotoxy(36, count - 5);
				coutchar(0, Place::returnPlace(count - 5, 36));
				TrafficLight::setPlace(36, count - 5, 255);
			}

			//Erases the Truck once it reaches the end of the screen
			if (count == 25)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoxy(36, 24 - i);
					coutchar(0, Place::returnPlace(24-i, 36));
					TrafficLight::setPlace(36, 24-i, 255);

					//Incremements the North counter
					if (flag == false){
						Vehicle::northCount++;
						flag = true;
					}
				}
			}
		}
	}

	//Handles Trucks coming from the South
	else if (dir == 3 && count != 1)
	{
		//Ensures there's nothing in front of the Truck
		if (TrafficLight::getPlace(45, count - 1) != 219 && TrafficLight::getPlace(44, count - 1) != 219)
		{
			//Prints out the Truck
			if (count >= 1)
			{
				gotoxy(44, count);
				coutchar(colour, 219);
				TrafficLight::setPlace(44, count, 219);

				if (count != 1)
					count--;
			}

			//Ensures the Truck doesn't leave the screen
			if (count < 22)
			{
				gotoxy(44, count + 5);
				coutchar(0, Place::returnPlace(count + 5, 44));
				TrafficLight::setPlace(44, count + 5, 255);
			}

			//Erases the Truck once it reaches the end of the screen
			if (count <= 1)
			{
				for (int i = 0; i < 7; i++)
				{
					gotoxy(44, i);
					coutchar(0, Place::returnPlace(i, 44));
					TrafficLight::setPlace(44, i, 255);

					//Incrememnts the South Counter
					if (flag == false){
						Vehicle::southCount++;
						flag = true;
					}
				}
			}

			//Used to remove an error'd vehicle.
			gotoxy(44, 25);
			coutcharbl(0, 3);
			gotoxy(44, 26);
			coutcharbl(0, 3);
		}
	}
}

