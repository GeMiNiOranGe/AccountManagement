#ifndef CADMINISTRATOR_H
#define CADMINISTRATOR_H
#pragma once

#include "CUser.h"
#include "CEmployee.h"
#include "HandleMain.h"

class CAdministrator:
	public CUser {
public:
	CAdministrator(string = "", string = "111111", string = "", string = "", string = "", string = "");

	void addEmployee(string strUsername);
	void eraseEmployee(string strUsername);
	void searchEmployee();
	void updateEmployee();
	void showInfoEmployee();
};

#endif