#pragma once
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

#include "account_type.hpp"

const std::string DEFAULT_PASSWORD = "111111";

class Account {
public:
	Account(AccountType _id = AccountType::NONE, std::string _username = "", std::string _password = DEFAULT_PASSWORD);

	const AccountType & get_account_type() const;
	const std::string & get_username() const;
	const std::string & get_password() const;

	void set_account_type(const AccountType &_id);
	void set_username(const std::string &_username);
	void set_password(const std::string &_password);

private:
	AccountType account_type;
	std::string password;
	std::string username;
	// TODO: add std::string strAccountType; and config in code
};

#endif // end ACCOUNT_HPP