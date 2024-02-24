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

	// bool is_success_change_pass(
	// 	std::string _username,
	// 	std::string _current_password,
	// 	std::string _new_password,
	// 	std::string _confirm_new_password
	// );

	void create_account(std::string _username);
	void delete_account(std::string _username);
	void update_account(Account _old_account, Account _new_account);
};

#endif // end ACCOUNTMANAGEMENT_HPP