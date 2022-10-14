#ifndef CADMINISTRATOR_H
#define CADMINISTRATOR_H
#pragma once

#include "CUser.h"

class CAdministrator:
	public CUser {
public:
	CAdministrator(string = "", string = "111111", string = "", string = "", string = "", string = "");

	void addEmployee();
	void eraseEmployee();
	void searchEmployee();
	void updateEmployee();
	void showInfoEmployee();
};

#endif