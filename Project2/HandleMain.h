#ifndef HANDLEMAIN_H
#define HANDLEMAIN_H
#pragma once

#include <string>
#include <fstream>
#include "CUser.h"
#include "Config.h"

using namespace std;

ofstream createFile(string fileName);
ifstream openFile(string fileName);
void deleteFile(string fileName);

template <class T> bool hasAccount(string strSourceFile, string strUsername, string strPassword = "") {
	ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser *pTempUser = new T;
		pTempUser->readAccount(fileIn);
		if ((strUsername == pTempUser->getUsername() && strPassword == "" || strUsername == pTempUser->getUsername() && strPassword == pTempUser->getPassword())
			&& pTempUser->getUsername() != "" && pTempUser->getPassword() != "") {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}

#endif
