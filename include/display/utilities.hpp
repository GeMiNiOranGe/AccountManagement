#pragma once
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>

#include "display/console_color.hpp"

struct InputResult {
    bool cancelled;
    std::string value;
};

bool is_open_file(std::ifstream & fin, const std::string & path);
bool is_open_file(std::ofstream & fout, const std::string & path);

std::string input_password();
InputResult input_text(bool hide_input = false, size_t max_length = 64);

void go_to_xy(SHORT x_coord, SHORT y_coord);
void warning(std::string message);
void success(std::string message);

template <typename data_type>
bool is_even(data_type value) {
    return (value % 2) == 0;
}
template <typename data_type>
bool is_odd(data_type value) {
    return (value % 2) != 0;
}

#endif  // end UTILITIES_HPP
