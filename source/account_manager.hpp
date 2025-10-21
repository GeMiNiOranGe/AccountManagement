#pragma once
#ifndef ACCOUNT_MANAGER_HPP
#define ACCOUNT_MANAGER_HPP

#include <iostream>
#include <functional>

#include "account_file_manager.hpp"
#include "config.hpp"
#include "utilities.hpp"

class AccountManager {
private:
	static void for_each_account(
		const std::function<bool(const Account &)> &callback
	);

public:
	static bool has_username(const std::string &_username);
	static bool has_account(const Account &_account);

	static Account get_account_details(const std::string &_username, const std::string &_password);

	static void create_account(const std::string &_username);
	static void delete_account(const std::string &_username);
	static void update_account(const Account &_old_account, const Account &_new_account);
};

#endif // end ACCOUNT_MANAGER_HPP