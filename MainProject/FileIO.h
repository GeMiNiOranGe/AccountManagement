#pragma once
#ifndef FILEIO_HPP
#define FILEIO_HPP

#include "AccountType.h"
#include "User.h"
#include <fstream>

namespace io {
	class File {
	public:
		static void read_account_from(std::ifstream &_fin, User &_user);
		static void read_info_from(std::ifstream &_fin, User &_user);
		
		static void write_account_from(User _user, std::ofstream &_fout);
		static void write_info_from(User _user, std::ofstream &_fout);
	};
} // namespace io

#endif // end FILEIO_HPP