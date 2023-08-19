#ifndef HANDLEMISCELLANEOUS_H
#define HANDLEMISCELLANEOUS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

enum class Color {
	BLACK,
	BLUE,
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_AQUA,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	BRIGHT_WHITE,
};

void encode_password(std::string & strHandle);

// 0 = Black  |  8 = Gray
// 1 = Blue   |  9 = Light Blue
// 2 = Green  | 10 = Light Green
// 3 = Aqua   | 11 = Light Aqua
// 4 = Red    | 12 = Light Red
// 5 = Purple | 13 = Light Purple
// 6 = Yellow | 14 = Light Yellow
// 7 = White  | 15 = Bright White
void textAndBackgroundColor(Color textColor, Color backgroundColor = Color::BLACK);
void gotoXY(short x, short y);
void warning(std::string strMessage);

template<typename data_type> bool is_even(data_type value) {
	return (value % 2) == 0;
}
template<typename data_type> bool is_odd(data_type value) {
	return (value % 2) != 0;
}

#endif