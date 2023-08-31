#pragma once
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include "User.hpp"
#include "FileIO.hpp"

// TODO: change class Employee into class Account
class Employee : public User {
public:
	Employee(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);

	bool is_success_change_pass(
		std::string _username,
		std::string _current_password,
		std::string _new_password,
		std::string _confirm_new_password
	);
};

#endif // end EMPLOYEE_HPP