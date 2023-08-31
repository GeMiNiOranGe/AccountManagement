#pragma once
#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP

#include "User.hpp"
#include "HandleMain.hpp"

class Administrator : public User {
public:
	Administrator(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);

	void add_employee(std::string _username);
	void erase_employee(std::string _username);
	void update_info_employee(std::string _username, std::string _info_updated, char _option);
};

#endif // end ADMINISTRATOR_HPP