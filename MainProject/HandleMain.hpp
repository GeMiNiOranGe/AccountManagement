#pragma once
#ifndef HANDLEMAIN_HPP
#define HANDLEMAIN_HPP

#include "AccountFileManager.hpp"
#include "AccountType.hpp"
#include "Config.hpp"

// bool has_username(std::string _username);
// bool has_account(std::string _username, std::string _password);

AccountType get_account_type(std::string _username, std::string _password);
bool is_default_password(Account _account);

#endif // end HANDLEMAIN_HPP