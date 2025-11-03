#pragma once
#ifndef ACCOUNT_FILE_IO_HPP
#define ACCOUNT_FILE_IO_HPP

#include <fstream>

#include "account.hpp"
#include "config.hpp"

class AccountFileIO {
private:
    static AccountType parse_role_text(const std::string &value);
    static std::string to_role_text(AccountType value);

public:
    static void read_file(std::ifstream &fin, Account &value);
    static void write_file(std::ofstream &fout, const Account &value);
};

#endif // end ACCOUNT_FILE_IO_HPP