#ifndef HANDLEMISCELLANEOUS_H
#define HANDLEMISCELLANEOUS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

enum class color {
	Black,
	Blue,
	Green,
	Aqua,
	Red,
	Purple,
	Yellow,
	White,
	Gray,
	LightBlue,
	LightGreen,
	LightAqua,
	LightRed,
	LightPurple,
	LightYellow,
	BrightWhite,
};

//All functions below can be used in 4 projects of data structures
void encodePassword(std::string & strHandle);

// 0 = Black  |  8 = Gray
// 1 = Blue   |  9 = Light Blue
// 2 = Green  | 10 = Light Green
// 3 = Aqua   | 11 = Light Aqua
// 4 = Red    | 12 = Light Red
// 5 = Purple | 13 = Light Purple
// 6 = Yellow | 14 = Light Yellow
// 7 = White  | 15 = Bright White
void textAndBackgroundColor(color textColor, color backgroundColor);
void resizeConsole(int width, int height);
void gotoXY(short x, short y);
void warning(std::string strMessage);
char * convertStringToChar(std::string strInput);

#endif