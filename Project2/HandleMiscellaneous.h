#ifndef HANDLEMISCELLANEOUS_H
#define HANDLEMISCELLANEOUS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "CUser.h"

using namespace std;

//All functions below can be used in 4 projects of data structures
void encodePassword(string & strHandle);
void textAndBackgroundColor(int textColor, int backgroundColor);
void resizeConsole(int width, int height);
void gotoXY(short x, short y);
void chooseWrong(string strMessage);
char* convertStringToChar(string strInput);

template <class T> bool hasAccount(string strSourceFile, string strUsername, string strPassword = "") {
	ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser *pTempUser = new T;
		pTempUser->readAccount(fileIn);
		if (strUsername == pTempUser->getUsername() && strPassword == "") {
			fileIn.close();
			return true;
		}
		if (strUsername == pTempUser->getUsername() && strPassword == pTempUser->getPassword()) {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}


#endif