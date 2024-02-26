#pragma once
#ifndef ACCOUNT_MANAGER_HPP
#define ACCOUNT_MANAGER_HPP

#include <iostream>

#include "account_file_manager.hpp"
#include "config.hpp"

class AccountManagement {
private:
	Account account;
public:
	AccountManagement(const Account & _account = Account());

	const Account & get_account() const;
	void set_account(const Account &_account);

	bool has_username(const std::string &_username);
	bool has_account(const Account &_account);

	Account get_account_details(const std::string &_username, const std::string &_password);

	void create_account(const std::string &_username);
	void delete_account(const std::string &_username);
	void update_account(const Account &_old_account, const Account &_new_account);
};

#endif // end ACCOUNT_MANAGER_HPP