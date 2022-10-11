#include "CUser.h"

CUser::CUser(string _fullName, string _address, string _phoneNumber, string _emailAddress, string _username, string _password) {
	this->fullName = _fullName;
	this->address = _address;
	this->phoneNumber = _phoneNumber;
	this->emailAddress = _emailAddress;
	this->username = _username;
	this->password = _password;
}
CUser::CUser(const CUser & tempUser) {
	this->fullName = tempUser.fullName;
	this->address = tempUser.address;
	this->phoneNumber = tempUser.phoneNumber;
	this->emailAddress = tempUser.emailAddress;
	this->username = tempUser.username;
	this->password = tempUser.password;
}
CUser::~CUser() {
}

string CUser::getFullName() {
	return this->fullName;
}
string CUser::getAddress() {
	return this->address;
}
string CUser::getPhoneNumber() {
	return this->phoneNumber;
}
string CUser::getEmailAddress() {
	return this->emailAddress;
}
string CUser::getUsername() {
	return this->username;
}
string CUser::getPassword() {
	return this->password;
}

void CUser::setFullName(string _fullName) {
	this->fullName = _fullName;
}
void CUser::setAddress(string _address) {
	this->address = _address;
}
void CUser::setPhoneNumber(string _phoneNumber) {
	this->phoneNumber = _phoneNumber;
}
void CUser::setEmailAddress(string _emailAddress) {
	this->emailAddress = _emailAddress;
}
void CUser::setUsername(string _username) {
	this->username = _username;
}
void CUser::setPassword(string _password) {
	this->password = _password;
}
