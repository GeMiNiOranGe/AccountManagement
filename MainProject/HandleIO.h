#ifndef HANDLEIO_H
#define HANDLEIO_H
#pragma once

#include <fstream>
#include "User.h"

// TODO: create 2 new functions, 1 scan and 1 print on console

namespace file {
	enum class AccountType {
		Administrator,
		Employee,
		//None,
	};
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

namespace console {
	namespace read {
		void account(User & user);
		void info(User & user);
		void all(User & user);
	} // namespace read
	namespace write {
		void account(User user);
		void info(User user);
		void all(User user);
	} // namespace write
} // namespace console

#endif 