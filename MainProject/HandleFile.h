#ifndef HANDLEFILE_H
#define HANDLEFILE_H
#pragma once

#include <fstream>
#include "CUser.h"

// TODO: create 2 new functions, 1 scan and 1 print on console

namespace handleFile {
	enum class AccountType {
		Administrator,
		Employee,
		//None,
	};
	namespace read {
		void account(CUser & userTemp, std::ifstream & fileIn);
		void info(CUser & userTemp, std::ifstream & fileIn);
	} // namespace read
	namespace write {
		void account(CUser & userTemp, std::ofstream & fileOut);
		void account(CUser & userTemp, std::ofstream & fileOut, AccountType _accountType);
		void info(CUser & userTemp, std::ofstream & fileOut);
	} // namespace write
} // namespace handleFile

#endif 