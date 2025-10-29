#pragma once
#ifndef USER_FILE_MANAGER_HPP
#define USER_FILE_MANAGER_HPP

#include <fstream>

#include "user.hpp"
#include "config.hpp"

class UserFileManager {
public:
	static void read_file(std::ifstream & _fin, User & _user);
	static void write_file(std::ofstream & _fout, const User & _user);
};

#endif // end USER_FILE_MANAGER_HPP