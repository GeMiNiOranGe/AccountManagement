#ifndef CADMINISTRATOR_H
#define CADMINISTRATOR_H
#pragma once

#include "CUser.h"
#include "HandleMain.h"
#include "UIHaveNoUX.h"

class CAdministrator:
	public CUser {
public:
	CAdministrator(string = "", string = "111111", string = "", string = "", string = "", string = "");

	void addEmployee(string);
	void eraseEmployee(string);
	void updateInfoEmployee(string, string, char);
	void showInfoAllEmployee();
};


#endif