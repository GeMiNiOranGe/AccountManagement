#pragma once
#ifndef USERMANAGEMENT_HPP
#define USERMANAGEMENT_HPP

#include "UserFileManager.hpp"

class UserManagement {
private:
	User user;

public:
	UserManagement(const User & _user = User());

	const User & get_user() const;
	void set_user(const User &_user);

	void create_user(const std::string &_username, const User &_user_information);
	void delete_user(const std::string &_username);
	void update_user(const std::string &_username, std::string _info_updated, char _option);
	User read_user(const std::string &_username);
};

#endif // end USERMANAGEMENT_HPP