#ifndef CADMINISTRATOR_H
#define CADMINISTRATOR_H
#pragma once

#include "User.h"
#include "HandleMain.h"
#include "HandleIO.h"
#include "UIHaveNoUX.h"

class Administrator : public User {
public:
	Administrator(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);

	void addEmployee(std::string);
	void eraseEmployee(std::string);
	void updateInfoEmployee(std::string, std::string, char);
	void showInfoAllEmployee();
};

#endif