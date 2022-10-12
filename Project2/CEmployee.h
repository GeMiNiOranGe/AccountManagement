#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#pragma once

#include "CUser.h"

class CEmployee:
	public CUser {
public:
	CEmployee(string = "", string = "", string = "", string = "", string = "", string = "111111");

	void viewInfoAccount();
	void changePassword();
};

#endif