#pragma once
#ifndef USER_FILE_IO_HPP
#define USER_FILE_IO_HPP

#include <fstream>
#include <sstream>

#include "config.hpp"
#include "user.hpp"

class UserFileIO {
public:
    static bool read_file(std::ifstream & fin, User & value);
    static void write_file(std::ofstream & fout, const User & value);
};

#endif  // end USER_FILE_IO_HPP
