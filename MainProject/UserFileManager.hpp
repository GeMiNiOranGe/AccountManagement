#pragma once
#ifndef USERFILEMANAGER_HPP
#define USERFILEMANAGER_HPP

#include <fstream>

#include "User.hpp"
#include "Config.hpp"

class UserFileManager {
public:
	static std::ifstream open_file(const std::string &_username);

	static void read_file(std::ifstream & _fin, User & _user);
	static void write_file(const User & _user, std::ofstream & _fout);
};

#endif // end USERFILEMANAGER_HPP