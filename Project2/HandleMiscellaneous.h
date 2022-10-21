#ifndef HANDLEMISCELLANEOUS_H
#define HANDLEMISCELLANEOUS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include "CUser.h"
#include "CAdministrator.h"
#include "CEmployee.h"

using namespace std;

void encodePassword(string & strHandle);
void textAndBackgroundColor(int textColor, int backgroundColor);
void resizeConsole(int width, int height);
void gotoXY(short x, short y);
void chooseWrong();
template <class T> bool checkUsername(string username) {
	ifstream fileIn;
	fileIn.open("Resources/Employees.txt");
	while (!fileIn.eof()) {
		CUser* x = new T;
		x->readAccount(fileIn);
		if (username == x->getUsername()) {
			fileIn.close();
			return false;
		}
	}
	fileIn.close();
	return true;
}

#endif