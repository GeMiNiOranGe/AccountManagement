#pragma once
#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <fstream>
#include "AccountType.hpp"
#include "Account.hpp"
#include "User.hpp"

namespace io {
	class File {
	public:
		static void read_account_from(std::ifstream &_fin, Account & _account);
		static void read_info_from(std::ifstream &_fin, User &_user);
		
		static void write_account_from(Account _account, std::ofstream &_fout);
		static void write_info_from(User _user, std::ofstream &_fout);
	};
} // namespace io

#endif // end FILEIO_HPP	