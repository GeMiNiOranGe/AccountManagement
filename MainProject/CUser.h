#ifndef CUSER_H
#define CUSER_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "HandleMiscellaneous.h"

class CUser {
public:
	CUser(std::string = "", std::string = "111111", std::string = "", std::string = "", std::string = "", std::string = "");
	CUser(const CUser &);
	~CUser();

	/* If getter have no "const", it's a combination of setter and getter, this function can use like this.
	Code:
	CUser.getFullName() = "Some string";
	cout << CUser.getFullName();
	Also, it have "const", so it's just a normal getter.
	Setter have "const", why ??? because i used reference for that function, and it can run faster.
	I am not sure it can run faster or not =))))) */

	const std::string & getUsername();
	const std::string & getPassword();
	const std::string & getFullName();
	const std::string & getAddress();
	const std::string & getPhoneNumber();
	const std::string & getEmailAddress();

	void setUsername(const std::string &);
	void setPassword(const std::string &);
	void setFullName(const std::string &);
	void setAddress(const std::string &);
	void setPhoneNumber(const std::string &);
	void setEmailAddress(const std::string &);

	void input();
	void output();

private:
	std::string strUsername;
	std::string strPassword;
	std::string strFullName;
	std::string strAddress;
	std::string strPhoneNumber;
	std::string strEmailAddress;
};

#endif