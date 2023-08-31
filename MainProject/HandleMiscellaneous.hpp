#pragma once
#ifndef HANDLEMISCELLANEOUS_HPP
#define HANDLEMISCELLANEOUS_HPP

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Color.hpp"

void encode_password(std::string & _password);

void set_color(Color text_color, Color background_color = Color::BLACK);
void go_to_xy(short x, short y);
void warning(std::string _message);

template<typename data_type> bool is_even(data_type value) {
	return (value % 2) == 0;
}
template<typename data_type> bool is_odd(data_type value) {
	return (value % 2) != 0;
}

#endif // end HANDLEMISCELLANEOUS_HPP