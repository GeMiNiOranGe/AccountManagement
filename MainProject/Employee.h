#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#pragma once

#include "User.h"
#include "HandleMain.h"
#include "HandleIO.h"

class Employee : public User {
public:
	Employee(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);

	bool isSuccessChangePass(std::string, std::string, std::string, std::string);
};

#endif