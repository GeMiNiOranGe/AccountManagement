#pragma once
#ifndef ACCOUNT_STORAGE_HPP
#define ACCOUNT_STORAGE_HPP

#include <iostream>
#include <functional>

#include "account_file_manager.hpp"
#include "config.hpp"
#include "utilities.hpp"

class AccountStorage {
private:
	static void for_each_account(
		const std::function<bool(const Account &)> &callback
	);

	static void process_accounts_file(
		const std::function<void(Account &, std::ofstream &)> &processor
	);

public:
	static bool has_username(const std::string &username);
	static bool has_account(const Account &_account);

	static Account get_account_details(
		const std::string &username,
		const std::string &password
	);

	static void create_account(const std::string &username);
	static void delete_account(const std::string &username);
	static void update_account(const Account &old_account,
		const Account &new_account
	);
};

#endif // end ACCOUNT_STORAGE_HPP