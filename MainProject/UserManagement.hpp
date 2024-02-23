#pragma once
#ifndef USERMANAGEMENT_HPP
#define USERMANAGEMENT_HPP

#include "UserFileManager.hpp"
#include "ConsoleIO.hpp"

class UserManagement {
private:
	User user;

public:
	UserManagement(const User & _user = User());

	const User & get_user() const;
	void set_user(const User &_user);

	// TODO: convert to read_user() method, return user
	void show_user(std::string _username);

	void create_user(std::string _username);
	void delete_user(std::string _username);
	void update_user(std::string _username, std::string _info_updated, char _option);
};

#endif // end USERMANAGEMENT_HPP