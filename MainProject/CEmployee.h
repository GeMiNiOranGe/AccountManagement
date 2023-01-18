#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#pragma once

#include "CUser.h"
#include "HandleMain.h"
#include "HandleMiscellaneous.h"
#include "Config.h"

class CEmployee:
	public CUser {
public:
	CEmployee(string = "", string = "111111", string = "", string = "", string = "", string = "");

	bool isSuccessChangePass(string, string, string, string);
};

#endif