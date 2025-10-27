#pragma once
#ifndef ACCOUNT_FILE_MANAGER_HPP
#define ACCOUNT_FILE_MANAGER_HPP

#include <fstream>

#include "account.hpp"
#include "config.hpp"

class AccountFileManager {
public:
    static void read_file(std::ifstream &fin, Account &account);
    static void write_file(std::ofstream &fout, const Account &account);
};

#endif // end ACCOUNT_FILE_MANAGER_HPP