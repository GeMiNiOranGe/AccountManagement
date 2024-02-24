#pragma once
#ifndef HANDLEMAIN_HPP
#define HANDLEMAIN_HPP

#include "AccountFileManager.hpp"
#include "AccountType.hpp"
#include "Config.hpp"

AccountType get_account_type(std::string _username, std::string _password);

#endif // end HANDLEMAIN_HPP