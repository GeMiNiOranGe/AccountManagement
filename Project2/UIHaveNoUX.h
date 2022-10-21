#ifndef UIHAVENOUX_H
#define UIHAVENOUX_H
#pragma once

#include "HandleMiscellaneous.h"

void loginAdmin(string & strUsername, string & strPassword);
void loginEmployees(string & strUsername, string & strPassword);
char chooseAdminOrEmployee();
char menuAdmin();
char menuEmployee();

#endif
