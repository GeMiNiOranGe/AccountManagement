#ifndef HANDLEIO_H
#define HANDLEIO_H
#pragma once

#include <fstream>
#include "CUser.h"

// TODO: create 2 new functions, 1 scan and 1 print on console

namespace file {
	enum class AccountType {
		Administrator,
		Employee,
		//None,
	};
	namespace read {
		void account(CUser & _user, std::ifstream & fileIn);
		void info(CUser & _user, std::ifstream & fileIn);
	} // namespace read
	namespace write {
		void account(CUser _user, std::ofstream & fileOut);
		void account(CUser _user, std::ofstream & fileOut, AccountType _accountType);
		void info(CUser _user, std::ofstream & fileOut);
	} // namespace write
} // namespace file

namespace console {
	namespace read {
		void account(CUser & _user);
		void info(CUser & _user);
		void all(CUser & _user);
	} // namespace read
	namespace write {
		void account(CUser _user);
		void info(CUser _user);
		void all(CUser _user);
	} // namespace write
} // namespace console

#endif 