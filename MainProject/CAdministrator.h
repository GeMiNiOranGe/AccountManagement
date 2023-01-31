#ifndef CADMINISTRATOR_H
#define CADMINISTRATOR_H
#pragma once

#include "CUser.h"
#include "HandleMain.h"
#include "UIHaveNoUX.h"

class CAdministrator :
	public CUser {
public:
	CAdministrator(std::string = "", std::string = "111111", std::string = "", std::string = "", std::string = "", std::string = "");

	void addEmployee(std::string);
	void eraseEmployee(std::string);
	void updateInfoEmployee(std::string, std::string, char);
	void showInfoAllEmployee();
};


#endif