#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#pragma once

#include "CUser.h"
#include "HandleMain.h"
#include "HandleFile.h"
#include "Config.h"

class CEmployee : public CUser {
public:
	CEmployee(std::string = "", std::string = "111111", std::string = "", std::string = "", std::string = "", std::string = "");

	bool isSuccessChangePass(std::string, std::string, std::string, std::string);
};

#endif