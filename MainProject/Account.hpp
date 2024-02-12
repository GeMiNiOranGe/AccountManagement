#pragma once
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Config.hpp"

class Account {
public:
	Account(std::string _id = "", std::string _password = DEFAULT_PASSWORD, std::string _username = "");

	const std::string & get_id() const;
	const std::string & get_username() const;
	const std::string & get_password() const;

	void set_id(const std::string &);
	void set_username(const std::string &);
	void set_password(const std::string &);

	void read_file(std::ifstream & _fin);
	void write_file(std::ofstream & _fout);

	bool is_success_change_pass(
		std::string _username,
		std::string _current_password,
		std::string _new_password,
		std::string _confirm_new_password
	);
private:
	std::string id;
	std::string password;
	std::string username;
	// TODO: add std::string strAccountType; and config in code
};

#endif // end ACCOUNT_HPP