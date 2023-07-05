#ifndef CUSER_H
#define CUSER_H
#pragma once

#include <iostream>
#include "HandleMiscellaneous.h"
#include "Config.h"

class User {
public:
	User(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);
	User(const User &);
	~User();

	std::string * get_properties();

	/* If getter have no "const", it's a combination of setter and getter, this function can use like this.
	Code:
	User.getFullName() = "Some string";
	cout << User.getFullName();
	Also, it have "const", so it's just a normal getter.
	Setter have "const", why ??? because i used reference for that function, and it can run faster.
	I am not sure it can run faster or not =))))) */

	const std::string & get_username();
	const std::string & get_password();
	const std::string & get_id();
	const std::string & get_full_name();
	const std::string & get_address();
	const std::string & get_phone_number();
	const std::string & get_email_address();

	void set_username(const std::string &);
	void set_password(const std::string &);
	void set_id(const std::string &);
	void set_full_name(const std::string &);
	void set_address(const std::string &);
	void set_phone_number(const std::string &);
	void set_email_address(const std::string &);

	void input();
	void output();

private:
	std::string username;
	std::string password;
	std::string id; // e.g: Id: EM82Na5s7d, EM is Employee, 82Na5s7d is base64 code 
	// TODO: add std::string strAccountType; and config in code
	std::string full_name;
	std::string address;
	std::string phone_number;
	std::string email_address;
};

#endif