#pragma once
#ifndef ACCOUNT_FILE_MANAGER_HPP
#define ACCOUNT_FILE_MANAGER_HPP

#include <fstream>

#include "account.hpp"

class AccountFileManager {
public:
	static void read_file(std::ifstream & _fin, Account & _account);
	static void write_file(const Account & _account, std::ofstream & _fout);
};

#endif // end ACCOUNT_FILE_MANAGER_HPP