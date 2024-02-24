#pragma once
#ifndef HANDLE_MAIN_HPP
#define HANDLE_MAIN_HPP

#include "account_file_manager.hpp"
#include "account_type.hpp"
#include "config.hpp"

AccountType get_account_type(std::string _username, std::string _password);


#endif // end HANDLE_MAIN_HPP