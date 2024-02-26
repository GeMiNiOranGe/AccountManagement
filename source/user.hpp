#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
public:
	User(std::string _id = "", std::string _full_name = "", std::string _address = "", std::string _phone_number = "", std::string _email_address = "");
	User(const User &_user);
	~User();

	const std::string & get_id() const;
	const std::string & get_full_name() const;
	const std::string & get_address() const;
	const std::string & get_phone_number() const;
	const std::string & get_email_address() const;

	void set_id(const std::string &_id);
	void set_full_name(const std::string &_full_name);
	void set_address(const std::string &_address);
	void set_phone_number(const std::string &_phone_number);
	void set_email_address(const std::string &_email_address);

private:
	std::string id; // TODO: e.g Id: EM82Na5s7d, EM is Employee, 82Na5s7d is base64 code 
	std::string full_name;
	std::string address;
	std::string phone_number;
	std::string email_address;
};

#endif // end USER_HPP