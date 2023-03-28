#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "functions.h"

using namespace std;

//prints charcters on the screen with a given color (Eg: 2 is green)
void coutc(int color, char* output)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
	cout << output;
	SetConsoleTextAttribute(handle, color);
}
//prints number on the screen with a given color
void coutc(int color, int output)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
	cout << output;
	SetConsoleTextAttribute(handle, color);
}
//prints character based on ASCII code with background colour of grey 
void coutchar(int color, int output)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color + (8*16));
	cout << char(output);
	SetConsoleTextAttribute(handle, color);
}

//prints character based on ASCII code with background colour of black
void coutcharbl(int color, int output)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
	cout << char(output);
	SetConsoleTextAttribute(handle, color);
}

//move cursor to location(x, y)
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
