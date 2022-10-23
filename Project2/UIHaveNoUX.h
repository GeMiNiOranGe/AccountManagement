#ifndef UIHAVENOUX_H
#define UIHAVENOUX_H
#pragma once

#include "HandleMiscellaneous.h"

char chooseAdminOrEmployee();
void loginAdmin(string & strUsername, string & strPassword);
void loginEmployees(string & strUsername, string & strPassword);
char menuAdmin();
char menuEmployee();

#endif
