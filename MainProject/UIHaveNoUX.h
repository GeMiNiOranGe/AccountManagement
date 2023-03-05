#ifndef UIHAVENOUX_H
#define UIHAVENOUX_H
#pragma once

#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include "HandleMiscellaneous.h"
//#include "HandleMain.h"
// if ((title.size() + fillSize) % 2 == 1) fillSize++; else sumSize++;
std::string formLogin(std::string & strUsername, std::string & strPassword);
void formInfo(short labelSize, short fillSize, std::wstring title);
char chooseAdminOrEmployee();
void loginAdmin(std::string & strUsername, std::string & strPassword);
void loginEmployees(std::string & strUsername, std::string & strPassword, int iMaxLogin);
void showAnEmployeeInfoElement(
	Color textColor,
	std::string strUsername,
	std::string strFullName,
	std::string strAddress,
	std::string strPhoneNumber,
	std::string strEmailAddress,
	std::string endType,
	char fillType = ' '
);
char menuAdmin();
char menuEmployee();
char menuUpdateInfo();

#endif
