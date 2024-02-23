#pragma once
#ifndef HANDLEMAIN_HPP
#define HANDLEMAIN_HPP

#include "AccountManagement.hpp"
#include "ConsoleIO.hpp"
#include "AccountType.hpp"

bool has_username(std::string _username);
bool has_account(std::string _username, std::string _password);

AccountType get_account_type(std::string _username, std::string _password);
bool is_default_password(std::string _username, std::string _password);

#endif // end HANDLEMAIN_HPP