#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#pragma once

#include "CUser.h"
#include "HandleMain.h"
#include "HandleFile.h"

class CEmployee : public CUser {
public:
	CEmployee(
		std::string _strUsername = "", std::string _strPassword = DEFAULT_PASSWORD, std::string _strId = "",
		std::string _strFullName = "", std::string _strAddress = "",
		std::string _strPhoneNumber = "", std::string _strEmailAddress = ""
	);

	bool isSuccessChangePass(std::string, std::string, std::string, std::string);
};

#endif