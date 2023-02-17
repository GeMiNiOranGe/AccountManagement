#ifndef CADMINISTRATOR_H
#define CADMINISTRATOR_H
#pragma once

#include "CUser.h"
#include "HandleMain.h"
#include "HandleFile.h"
#include "UIHaveNoUX.h"

class CAdministrator : public CUser {
public:
	CAdministrator(
		std::string _strUsername = "", std::string _strPassword = DEFAULT_PASSWORD, std::string _strId = "",
		std::string _strFullName = "", std::string _strAddress = "",
		std::string _strPhoneNumber = "", std::string _strEmailAddress = ""
	);

	void addEmployee(std::string);
	void eraseEmployee(std::string);
	void updateInfoEmployee(std::string, std::string, char);
	void showInfoAllEmployee();
};

#endif