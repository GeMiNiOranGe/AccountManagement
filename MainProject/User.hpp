#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "Config.hpp"

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

#endif // end USER_HPP