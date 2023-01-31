#ifndef UIHAVENOUX_H
#define UIHAVENOUX_H
#pragma once

#include <iomanip>
#include "HandleMiscellaneous.h"
//#include "HandleMain.h"

std::string formLogin(std::string & strUsername, std::string & strPassword);
char chooseAdminOrEmployee();
void loginAdmin(std::string & strUsername, std::string & strPassword);
void loginEmployees(std::string & strUsername, std::string & strPassword, int iMaxLogin);
void showAnEmployeeInfoElement(
	color textColor,
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
