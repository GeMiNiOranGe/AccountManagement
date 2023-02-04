#ifndef HANDLEFILE_H
#define HANDLEFILE_H
#pragma once

#include "CUser.h"

namespace handleFile {
	namespace read {
		void account(CUser & userTemp, std::ifstream & fileIn);
		void info(CUser & userTemp, std::ifstream & fileIn);
	} // namespace read
	namespace write {
		void account(CUser & userTemp, std::ofstream & fileOut);
		void info(CUser & userTemp, std::ofstream & fileOut);
	} // namespace write
} // namespace handleFile

#endif 