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

	/* If getter have no "const", it's a combination of setter and getter, this function can use like this.
	Code:
	CUser.getFullName() = "Some string";
	cout << CUser.getFullName();
	Also, it have "const", so it's just a normal getter.
	Setter have "const", why ??? because i used reference for that function, and it can run faster.
	I am not sure it can run faster or not =))))) */

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