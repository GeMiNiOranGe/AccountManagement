#ifndef HANDLEMAIN_H
#define HANDLEMAIN_H
#pragma once

#include <string>
#include <fstream>
#include "CUser.h"
#include "Config.h"

using namespace std;

ofstream createFile(string strUsername);
ifstream openFile(string strUsername);
void deleteFile(string strUsername);

//Step 1: rename Employees.txt into EmployeesTemp.txt
//Step 2: create a new Employees.txt and open the file is renamed (EmployeesTemp.txt)
//Step 3: write from the file is renamed (EmployeesTemp.txt) to Employees.txt and don't write the employee want to delete
//Step 4: delete the file is renamed (EmployeesTemp.txt)
void deleteAccount(string strSourceFile, string strUsername);
void showAccountInfo(string strUsername);

bool hasUsername(string strSourceFile, string strUsername);
bool hasAccount(string strSourceFile, string strUsername, string strPassword);

#endif
