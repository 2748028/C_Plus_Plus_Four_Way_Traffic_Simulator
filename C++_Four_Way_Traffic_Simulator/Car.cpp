//Traffic Simulator 2016

#include "Car.h"
#include "TrafficLight.h"

Car::Car()
{
	/*
	0 - West
	1 - East
	2 - North
	3 - South
	*/

	//Randomizes the Car's colour
	colour = rand() % 16;
	if (colour == 8)
		colour = 15;

	//Randomizes the Car's direction
	dir = rand() % 4;
	if (dir == 0)
	{
		count = 2;
	}
	else if (dir == 1)
	{
		count = 80;
	}
	else if (dir == 2)
	{
		count = 2;
	}
	else if (dir == 3)
	{
		count = 25;
	}

	flag = false;
}

Car::~Car()
{
	delete this;
}

//Handles the Car updating
void Car::updateVehicle()
{
	//Handles Cars coming from the West
	if (dir == 0 && count != 81)
	{
		//Ensures there is nothing in front of the Car
		if (TrafficLight::getPlace(count + 1, 15) != 219 && TrafficLight::getPlace(count + 1, 14) != 219)
		{
			//Prints out the Car
			if (count < 80)
			{
				gotoxy(count, 14);
				coutchar(colour, 219);
				TrafficLight::setPlace(count, 14, 219);
				gotoxy(count - 1, 14);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 1, 14, 219);
				gotoxy(count - 2, 14);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 2, 14, 219);

			}

			//Ensures the Car doesn't go off the screen
			if (count > 2)
			{
				gotoxy(count - 3, 14);
				coutchar(0, Place::returnPlace(14,count - 3));
				TrafficLight::setPlace(count - 3, 14, 255);
			}

			//Erases the Car once it reaches the end
			if (count == 80)
			{
				gotoxy(count - 2, 14);
				coutchar(0, Place::returnPlace(14, count - 2));
				TrafficLight::setPlace(count - 2, 14, 255);
				gotoxy(count - 1, 14);
				coutchar(0, Place::returnPlace(14, count - 1));
				TrafficLight::setPlace(count - 1, 14, 255);

				//Increments the West counter
				if (flag == false){
					Vehicle::westCount++;
					flag = true;
				}
			}
				if (count < 80)
					count++;	
		}
	}

	//Handles the Cars coming from the East
	else if (dir == 1 && count != 3)
	{
		//Ensures there is nothing in front of the Car
		if (TrafficLight::getPlace(count - 4, 9) != 219 && TrafficLight::getPlace(count - 4, 10) != 219)
		{
			if (count > 3)
			{
				//Prints out the Car
				gotoxy(count - 1, 10);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 1, 10, 219);
				gotoxy(count - 2, 10);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 2, 10, 219);
				gotoxy(count - 3, 10);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 3, 10, 219);

			}
			//Ensures the Car doesn't go off the screen
			if (count >= 3)
			{
				gotoxy(count, 10);
				coutchar(0, Place::returnPlace(10, count));
				TrafficLight::setPlace(count, 10, 255);
			}
			//Erases the Car at the end of the window
			if (count <= 4)
			{
				gotoxy(1, 10);
				coutchar(0, Place::returnPlace(10, 1));
				TrafficLight::setPlace(1, 10, 255);
				gotoxy(2, 10);
				coutchar(0, Place::returnPlace(10, 2));
				TrafficLight::setPlace(2, 10, 255);
				gotoxy(3, 10);
				coutchar(0, Place::returnPlace(10, 3));
				TrafficLight::setPlace(3, 10, 255);

				//Increments the East counter
				if (flag == false){
					Vehicle::eastCount++;
					flag = true;
				}
			}

			if (count >= 4)
				count--;

		}
	}

	//Handles the Cars coming from the North
	else if (dir == 2 && count != 25)
	{
		//Ensures there is nothing in front of the Car
		if (TrafficLight::getPlace(35, count + 1) != 219 && TrafficLight::getPlace(36, count + 1) != 219)
		{
			//Prints out the Car
			if (count < 25)
			{
				gotoxy(36, count);
				coutchar(colour, 219);
				TrafficLight::setPlace(36, count, 219);
				gotoxy(36, count - 1);
				coutchar(colour, 219);
				TrafficLight::setPlace(36, count - 1, 219);

				count++;
			}

			//Ensures the Car doesn't go off the screen
			if (count > 2)
			{
				gotoxy(36, count - 3);
				coutchar(0, Place::returnPlace(count - 3, 36));
				TrafficLight::setPlace(36, count - 3, 255);
			}

			//Erases the Car when it reaches the end
			if (count == 25)
			{
				gotoxy(36, 23);
				coutchar(0, Place::returnPlace(23, 36));
				TrafficLight::setPlace(36, 23, 255);

				gotoxy(36, 24);
				coutchar(0, Place::returnPlace(24, 36));
				TrafficLight::setPlace(36, 24, 255);

				//Inrcements the North counter
				if (flag == false){
					Vehicle::northCount++;
					flag = true;
				}
			}
		}
	}

	//Handles the Cars coming from the South
	else if (dir == 3 && count != 1)
	{
		//Ensures that nothing is in front of the Car
		if (TrafficLight::getPlace(45, count - 1) != 219 && TrafficLight::getPlace(44, count - 1) != 219)
		{
			//Prints the Car
			if (count >= 1)
			{
				gotoxy(44, count);
				coutchar(colour, 219);
				TrafficLight::setPlace(44, count, 219);

				if (count != 1)
					count--;
			}

			//Ensures that the Car doesn't go off the screen
			if (count < 23)
			{
				gotoxy(44, count + 3);
				coutchar(0, Place::returnPlace(count + 3, 44));
				TrafficLight::setPlace(44, count + 3, 255);

				gotoxy(44, 25);
				coutcharbl(0, 3);
			}
			
			//Erases the Car once it reaches the end
			if (count <= 1)
			{
				gotoxy(44, 3);
				coutchar(0, Place::returnPlace(3, 44));
				TrafficLight::setPlace(44, 3, 255);
				gotoxy(44, 2);
				coutchar(0, Place::returnPlace(2, 44));
				TrafficLight::setPlace(44, 2, 255);
				gotoxy(44, 1);
				coutchar(0, Place::returnPlace(1, 44));
				TrafficLight::setPlace(44, 1, 255);

				//Increments the South counter
				if (flag == false){
					Vehicle::southCount++;
					flag = true;
				}
			}
		}

		
	}
}

