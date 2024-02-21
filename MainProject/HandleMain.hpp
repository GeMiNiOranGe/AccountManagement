#pragma once
#ifndef HANDLEMAIN_HPP
#define HANDLEMAIN_HPP

#include "UserManagement.hpp"
#include "Account.hpp"
#include "ConsoleIO.hpp"
#include "AccountType.hpp"

std::ofstream create_file(std::string _username);
std::ifstream open_file(std::string _username);
void delete_file(std::string _username);

void show_account_info(std::string _username);

bool has_username(std::string _username);
bool has_account(std::string _username, std::string _password);

AccountType get_account_type(std::string _username, std::string _password);
bool is_default_password(std::string _username, std::string _password);
#endif // end HANDLEMAIN_HPP