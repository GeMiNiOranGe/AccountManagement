#ifndef HANDLEMAIN_H
#define HANDLEMAIN_H
#pragma once

#include <string>
#include <fstream>

template <class T> bool hasAccount(string strSourceFile, string strUsername, string strPassword = "") {
	ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser *pTempUser = new T;
		pTempUser->readAccount(fileIn);
		if (strUsername == pTempUser->getUsername() && strPassword == "" || strUsername == pTempUser->getUsername() && strPassword == pTempUser->getPassword()) {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}

#endif
