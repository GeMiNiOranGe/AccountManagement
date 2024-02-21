#pragma once
#ifndef USERMANAGEMENT_HPP
#define USERMANAGEMENT_HPP

#include "User.hpp"
#include "Account.hpp"
#include "HandleMain.hpp"
#include "Config.hpp"
// #include "ConsoleIO.hpp"
#include "IReader.hpp"
#include "IWriter.hpp"

class UserManagement :public IReader, public IWriter {
private:
	User user;

public:
	UserManagement(const User & _user = User());

	const User & get_user();

	void read_file(std::ifstream & _fin) override;
	void write_file(std::ofstream & _fout) override;

	void create_account(std::string _username);
	void delete_account(std::string _username);
	void update_information_user(std::string _username, std::string _info_updated, char _option);
};

#endif // end USERMANAGEMENT_HPP