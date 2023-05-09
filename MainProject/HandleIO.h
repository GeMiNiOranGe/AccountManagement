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
		void account(std::ifstream & fileIn, CUser & user);
		void info(std::ifstream & fileIn, CUser & user);
	} // namespace read
	namespace write {
		void account(CUser user, std::ofstream & fileOut);
		void account(CUser user, std::ofstream & fileOut, AccountType _accountType);
		void info(CUser user, std::ofstream & fileOut);
	} // namespace write
} // namespace file

namespace console {
	namespace read {
		void account(CUser & user);
		void info(CUser & user);
		void all(CUser & user);
	} // namespace read
	namespace write {
		void account(CUser user);
		void info(CUser user);
		void all(CUser user);
	} // namespace write
} // namespace console

#endif 