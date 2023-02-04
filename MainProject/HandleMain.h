#ifndef HANDLEMAIN_H
#define HANDLEMAIN_H
#pragma once

#include <string>
#include <fstream>
#include "CUser.h"
#include "Config.h"
#include "HandleFile.h"

std::ofstream createFile(std::string strUsername);
std::ifstream openFile(std::string strUsername);
void deleteFile(std::string strUsername);

//Step 1: rename Employees.txt into EmployeesTemp.txt
//Step 2: create a new Employees.txt and open the file is renamed (EmployeesTemp.txt)
//Step 3: write from the file is renamed (EmployeesTemp.txt) to Employees.txt and don't write the employee want to delete
//Step 4: delete the file is renamed (EmployeesTemp.txt)
void deleteAccount(std::string strSourceFile, std::string strUsername);
void showAccountInfo(std::string strUsername);

bool hasUsername(std::string strSourceFile, std::string strUsername);
bool hasAccount(std::string strSourceFile, std::string strUsername, std::string strPassword);

#endif