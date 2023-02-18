#ifndef CUSER_H
#define CUSER_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "HandleMiscellaneous.h"

using namespace std;

class CUser {
public:
	CUser(string = "", string = "111111", string = "", string = "", string = "", string = "");
	CUser(const CUser &);
	~CUser();

	const string& getUsername();
	const string& getPassword();
	const string& getFullName();
	const string& getAddress();
	const string& getPhoneNumber();
	const string& getEmailAddress();

	void setUsername(const string&);
	void setPassword(const string&);
	void setFullName(const string&);
	void setAddress(const string&);
	void setPhoneNumber(const string&);
	void setEmailAddress(const string&);

	void readAccount(ifstream&);
	void writeAccount(ofstream&);
	void readInfo(ifstream&);
	void writeInfo(ofstream&);

	void input();
	void output();
private:
	string strUsername;
	string strPassword;
	string strFullName;
	string strAddress;
	string strPhoneNumber;
	string strEmailAddress;
};

#endif