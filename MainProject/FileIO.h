#ifndef HANDLEIO_H
#define HANDLEIO_H
#pragma once

#include <fstream>
#include "User.h"
#include "AccountType.h"

namespace file {
	namespace read {
		void account(std::ifstream & fileIn, User & user);
		void info(std::ifstream & fileIn, User & user);
	} // namespace read
	namespace write {
		void account(User user, std::ofstream & fileOut);
		void account(User user, std::ofstream & fileOut, AccountType _accountType);
		void info(User user, std::ofstream & fileOut);
	} // namespace write
} // namespace file

#endif 