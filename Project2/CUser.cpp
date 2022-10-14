#include "CUser.h"

CUser::CUser(string _username, string _password, string _fullName, string _address, string _phoneNumber, string _emailAddress) {
	this->username = _username;
	this->password = _password;
	this->fullName = _fullName;
	this->address = _address;
	this->phoneNumber = _phoneNumber;
	this->emailAddress = _emailAddress;
}
CUser::CUser(const CUser & tempUser) {
	this->username = tempUser.username;
	this->password = tempUser.password;
	this->fullName = tempUser.fullName;
	this->address = tempUser.address;
	this->phoneNumber = tempUser.phoneNumber;
	this->emailAddress = tempUser.emailAddress;
}
CUser::~CUser() {
}

const string& CUser::getUsername() {
	return this->username;
}
const string& CUser::getPassword() {
	return this->password;
}
const string& CUser::getFullName() {
	return this->fullName;
}
const string& CUser::getAddress() {
	return this->address;
}
const string& CUser::getPhoneNumber() {
	return this->phoneNumber;
}
const string& CUser::getEmailAddress() {
	return this->emailAddress;
}

void CUser::setUsername(const string& _username) {
	this->username = _username;
}
void CUser::setPassword(const string& _password) {
	this->password = _password;
}
void CUser::setFullName(const string& _fullName) {
	this->fullName = _fullName;
}
void CUser::setAddress(const string& _address) {
	this->address = _address;
}
void CUser::setPhoneNumber(const string& _phoneNumber) {
	this->phoneNumber = _phoneNumber;
}
void CUser::setEmailAddress(const string& _emailAddress) {
	this->emailAddress = _emailAddress;
}

void CUser::input() {
	cin >> this->fullName;
	cin >> this->address;
	cin >> this->phoneNumber;
	cin >> this->emailAddress;
}
void CUser::output() {
	cout << this->fullName << endl;
	cout << this->address << endl;
	cout << this->phoneNumber << endl;
	cout << this->emailAddress << endl;
}
