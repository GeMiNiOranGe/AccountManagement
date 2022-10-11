#ifndef CUSER_H
#define CUSER_H
#pragma once

#include <string>
using std::string;

class CUser {
public:
	CUser(string = "", string = "", string = "", string = "", string = "", string = "111111");
	CUser(const CUser &);
	~CUser();

	string getFullName();
	string getAddress();
	string getPhoneNumber();
	string getEmailAddress();
	string getUsername();
	string getPassword();

	void setFullName(string);
	void setAddress(string);
	void setPhoneNumber(string);
	void setEmailAddress(string);
	void setUsername(string);
	void setPassword(string);
private:
	string fullName;
	string address;
	string phoneNumber;
	string emailAddress;
	string username;
	string password;
};

#endif