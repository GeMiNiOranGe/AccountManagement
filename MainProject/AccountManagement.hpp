#pragma once
#ifndef ACCOUNTMANAGEMENT_HPP
#define ACCOUNTMANAGEMENT_HPP

#include <iostream>

#include "AccountFileManager.hpp"
#include "Config.hpp"

class AccountManagement {
private:
	Account account;
public:
	AccountManagement(const Account & _account = Account());

	const Account & get_account() const;
	void set_account(const Account &_account);

	bool has_username(const std::string &_username);
	bool has_account(const Account &_account);

	void create_account(const std::string &_username);
	void delete_account(const std::string &_username);
	void update_account(const Account &_old_account, const Account &_new_account);
};

#endif // end ACCOUNTMANAGEMENT_HPP