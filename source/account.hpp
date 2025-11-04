#pragma once
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

#include "account_role.hpp"
#include "config.hpp"

class Account {
public:
	Account(AccountRole _role = AccountRole::NONE, std::string _username = "", std::string _password = DEFAULT_PASSWORD);

	const AccountRole & get_role() const;
	const std::string & get_username() const;
	const std::string & get_password() const;

	void set_role(const AccountRole &_role);
	void set_username(const std::string &_username);
	void set_password(const std::string &_password);

private:
	AccountRole role;
	std::string password;
	std::string username;
};

#endif // end ACCOUNT_HPP