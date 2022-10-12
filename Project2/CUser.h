#ifndef CUSER_H
#define CUSER_H
#pragma once

#include <string>
#include <iostream>

using namespace std;

class CUser {
public:
	CUser(string = "", string = "", string = "", string = "", string = "", string = "111111");
	CUser(const CUser &);
	~CUser();
	
	/* If getter have no "const", it's a combination of setter and getter, this function can use like this.
	Code: 
	CUser.getFullName() = "Some string";
	cout << CUser.getFullName();
	Also, it have "const", so it's just a normal getter.
	Setter have "const", why ??? because i used reference for that function, and it can run faster.
	I am not sure it can run faster or not =))))) */

	const string& getFullName();
	const string& getAddress();
	const string& getPhoneNumber();
	const string& getEmailAddress();
	const string& getUsername();
	const string& getPassword();

	void setFullName(const string&);
	void setAddress(const string&);
	void setPhoneNumber(const string&);
	void setEmailAddress(const string&);
	void setUsername(const string&);
	void setPassword(const string&);

	void input();
	void output();
private:
	string fullName;
	string address;
	string phoneNumber;
	string emailAddress;
	string username;
	string password;
};

#endif