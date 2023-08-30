#ifndef HANDLEMISCELLANEOUS_H
#define HANDLEMISCELLANEOUS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Color.h"

void encode_password(std::string & _password);

void textAndBackgroundColor(Color text_color, Color background_color = Color::BLACK);
void gotoXY(short x, short y);
void warning(std::string _message);

template<typename data_type> bool is_even(data_type value) {
	return (value % 2) == 0;
}
template<typename data_type> bool is_odd(data_type value) {
	return (value % 2) != 0;
}

#endif