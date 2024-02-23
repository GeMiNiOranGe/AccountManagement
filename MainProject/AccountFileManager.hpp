#pragma once
#ifndef ACCOUNTFILEMANAGER_HPP
#define ACCOUNTFILEMANAGER_HPP

#include <fstream>

#include "Account.hpp"

class AccountFileManager {
public:
	static void read_file(std::ifstream & _fin, Account & _account);
	static void write_file(const Account & _account, std::ofstream & _fout);
};

#endif // end ACCOUNTFILEMANAGER_HPP