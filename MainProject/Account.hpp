#pragma once
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

#include "Config.hpp"

class Account {
public:
	Account(std::string _id = "", std::string _username = "", std::string _password = DEFAULT_PASSWORD);

	const std::string & get_id() const;
	const std::string & get_username() const;
	const std::string & get_password() const;

	void set_id(const std::string &);
	void set_username(const std::string &);
	void set_password(const std::string &);

private:
	std::string id;
	std::string password;
	std::string username;
	// TODO: add std::string strAccountType; and config in code
};

#endif // end ACCOUNT_HPP