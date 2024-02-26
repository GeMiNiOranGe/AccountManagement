#pragma once
#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include "user_file_manager.hpp"

class UserManager {
private:
	User user;

public:
	UserManager(const User & _user = User());

	const User & get_user() const;
	void set_user(const User &_user);

	void create_user(const std::string &_username, const User &_user_information);
	void delete_user(const std::string &_username);
	void update_user(const std::string &_username, std::string _info_updated, char _option);
	User read_user(const std::string &_username);
};

#endif // end USER_MANAGER_HPP