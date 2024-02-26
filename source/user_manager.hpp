#pragma once
#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include "user_file_manager.hpp"

class UserManager {
public:
	static void create_user(const std::string &_username, const User &_user_information);
	static void delete_user(const std::string &_username);
	static void update_user(const std::string &_username, std::string _info_updated, char _option);
	static User read_user(const std::string &_username);
};

#endif // end USER_MANAGER_HPP