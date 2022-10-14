#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#pragma once

#include "CUser.h"

class CEmployee:
	public CUser {
public:
	CEmployee(string = "", string = "111111", string = "", string = "", string = "", string = "");

	void viewInfoAccount();
	void changePassword();
};

#endif