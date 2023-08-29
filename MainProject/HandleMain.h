#pragma once
#ifndef HANDLEMAIN_HPP
#define HANDLEMAIN_HPP

#include <string>
#include <fstream>
#include "User.h"
#include "Config.h"
#include "FileIO.h"
#include "ConsoleIO.h"
#include "AccountType.h"
#include "LoginStatus.h"

std::ofstream create_file(std::string _username);
std::ifstream open_file(std::string _username);
void delete_file(std::string _username);

void delete_account(std::string _username);
void show_account_info(std::string _username);

bool has_username(std::string _username);
bool has_account(std::string _username, std::string _password);

AccountType get_account_type(std::string _username, std::string _password);

#endif // end HANDLEMAIN_HPP