#pragma once
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

const std::string DEFAULT_PASSWORD = "111111";

class Account {
public:
	Account(std::string _id = "", std::string _username = "", std::string _password = DEFAULT_PASSWORD);

	const std::string & get_id() const;
	const std::string & get_username() const;
	const std::string & get_password() const;

	void set_id(const std::string &_id);
	void set_username(const std::string &_username);
	void set_password(const std::string &_password);

private:
	std::string id;
	std::string password;
	std::string username;
	// TODO: add std::string strAccountType; and config in code
};

#endif // end ACCOUNT_HPP