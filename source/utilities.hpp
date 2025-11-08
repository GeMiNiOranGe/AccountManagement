#pragma once
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <string>

#include "console_color.hpp"

bool is_open_file(std::ifstream &fin, const std::string &path);
bool is_open_file(std::ofstream &fout, const std::string &path);

void encode_password(std::string & _password);

void go_to_xy(short x, short y);
void warning(std::string message);
void success(std::string message);

template<typename data_type> bool is_even(data_type value) {
    return (value % 2) == 0;
}
template<typename data_type> bool is_odd(data_type value) {
    return (value % 2) != 0;
}

#endif // end UTILITIES_HPP