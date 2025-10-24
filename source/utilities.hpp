#pragma once
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <fstream>

bool is_open_file(std::ifstream &fin, const std::string &path);
bool is_open_file(std::ofstream &fout, const std::string &path);

#endif // end UTILITIES_HPP