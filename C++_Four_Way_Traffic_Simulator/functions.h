//This is technically Khalil's

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//prints characters on the screen with a given color (Eg: 2 is green)
void coutc(int color, char* output);

//prints number on the screen with a given color
void coutc(int color, int output);

//prints character based on ASCII code with background colour of grey 
void coutchar(int color, int output); //Used to draw the world "map".

//prints character based on ASCII code with background colour of black
void coutcharbl(int color, int output); //Used to draw the world "map".

//move cursor to location(x, y)
void gotoxy(short x, short y);

#endif
