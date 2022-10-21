#ifndef CUSER_H
#define CUSER_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>

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

	virtual void readAccount(ifstream&);
	virtual void readInfo(ifstream&);
	virtual void writeInfo(ofstream&);
	virtual ofstream createFile(string&);
	virtual void OpenFile(ifstream&, char* &);
	virtual void DeleteFile(string);

	void input();
	void output();
private:
	string username;
	string password;
	string fullName;
	string address;
	string phoneNumber;
	string emailAddress;
};

#endif