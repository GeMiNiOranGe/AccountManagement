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
char* convertStringToChar(string strInput);
template <class T> bool hasUsername(string strSourceFile, string strUsername) {
	ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser *tempUser = new T;
		tempUser->readAccount(fileIn);
		if (strUsername == tempUser->getUsername()) {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
template <class T> bool isLogin(string strSourceFile, string strUsername, string strPassword) {
	ifstream FileIn;
	FileIn.open(strSourceFile.c_str(), ios_base::in);
	while (!FileIn.eof()) {
		CUser *tempUser = new T;
		tempUser->readAccount(FileIn);
		if (tempUser->getUsername() + tempUser->getPassword() == strUsername + strPassword) {
			FileIn.close();
			return true;
		}
	}
	FileIn.close();
	return false;
}


#endif