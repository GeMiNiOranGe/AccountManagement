#pragma once
#ifndef FILEMANAGEMENT_HPP
#define FILEMANAGEMENT_HPP

#include <fstream>
#include <string>

#include "Config.hpp"
#include "User.hpp"
#include "Account.hpp"

class FileManager {
public:
	static std::ifstream open_file(const std::string &_username);

	static void read_file(std::ifstream & _fin, User & _user);
	static void read_file(std::ifstream & _fin, Account & _account);
	
	static void write_file(const User & _user, std::ofstream & _fout);
	static void write_file(const Account & _account, std::ofstream & _fout);
};

#endif // end FILEMANAGEMENT_HPP