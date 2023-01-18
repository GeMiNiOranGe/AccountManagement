#ifndef HANDLEMISCELLANEOUS_H
#define HANDLEMISCELLANEOUS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

//All functions below can be used in 4 projects of data structures
void encodePassword(string & strHandle);
// 0 = Black  |  8 = Gray
// 1 = Blue   |  9 = Light Blue
// 2 = Green  | 10 = Light Green
// 3 = Aqua   | 11 = Light Aqua
// 4 = Red    | 12 = Light Red
// 5 = Purple | 13 = Light Purple
// 6 = Yellow | 14 = Light Yellow
// 7 = White  | 15 = Bright White
void textAndBackgroundColor(int textColor, int backgroundColor);
void resizeConsole(int width, int height);
void gotoXY(short x, short y);
void warning(string strMessage);
char* convertStringToChar(string strInput);


#endif