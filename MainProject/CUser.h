#ifndef CUSER_H
#define CUSER_H
#pragma once

#include <iostream>
#include "HandleMiscellaneous.h"
#include "Config.h"

class CUser {
public:
	CUser(
		std::string _strUsername = "", std::string _strPassword = DEFAULT_PASSWORD, std::string _strId = "",
		std::string _strFullName = "", std::string _strAddress = "",
		std::string _strPhoneNumber = "", std::string _strEmailAddress = ""
	);
	CUser(const CUser &);
	~CUser();

	std::string * getProperties();

	/* If getter have no "const", it's a combination of setter and getter, this function can use like this.
	Code:
	CUser.getFullName() = "Some string";
	cout << CUser.getFullName();
	Also, it have "const", so it's just a normal getter.
	Setter have "const", why ??? because i used reference for that function, and it can run faster.
	I am not sure it can run faster or not =))))) */

	const std::string & getUsername();
	const std::string & getPassword();
	const std::string & getId();
	const std::string & getFullName();
	const std::string & getAddress();
	const std::string & getPhoneNumber();
	const std::string & getEmailAddress();

	void setUsername(const std::string &);
	void setPassword(const std::string &);
	void setId(const std::string &);
	void setFullName(const std::string &);
	void setAddress(const std::string &);
	void setPhoneNumber(const std::string &);
	void setEmailAddress(const std::string &);

	void input();
	void output();

private:
	std::string strUsername;
	std::string strPassword;
	std::string strId; // e.g: Id: EM82Na5s7d, EM is Employee, 82Na5s7d is base64 code 
	// TODO: add std::string strAccountType; and config in code
	std::string strFullName;
	std::string strAddress;
	std::string strPhoneNumber;
	std::string strEmailAddress;
};

#endif