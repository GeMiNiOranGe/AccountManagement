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

void CUser::readAccount(ifstream &fileIn) {
	getline(fileIn, this->username, ',');
	getline(fileIn, this->password);
}
void CUser::readInfo(ifstream& fileIn) {
	getline(fileIn, this->fullName);
	getline(fileIn, this->address);
	getline(fileIn, this->phoneNumber);
	getline(fileIn, this->emailAddress);
}
void CUser::writeInfo(ofstream& fileOut) {
	fileOut << this->fullName << endl;
	fileOut << this->address << endl;
	fileOut << this->phoneNumber << endl;
	fileOut << this->emailAddress << endl;
}
ofstream CUser::createFile(string & fileName) {
	string filePath = fileName + ".txt";
	ofstream fileTemp(filePath);
	return fileTemp;
}
void CUser::OpenFile(ifstream &fileIn, char* &fileName) {
	string str = (string)fileName;
	string filePath = str + ".TXT";
	fileName = new char[filePath.length() + 1];
	strcpy_s(fileName, filePath.length() + 1, filePath.c_str());
	if (fileName != NULL) {
		fileIn.open(fileName, ios_base::in);
	}
	delete[] fileName;
}
void CUser::DeleteFile(string fileName) {
	string filePath = "\"del " + fileName + ".txt\"";
	char* strDelete = new char[filePath.length() + 1];
	strcpy_s(strDelete, filePath.length() + 1, filePath.c_str());
	system(strDelete);
}

void CUser::input() {
	cin.ignore();
	getline(cin, this->fullName);
	getline(cin, this->address);
	getline(cin, this->phoneNumber);
	getline(cin, this->emailAddress);
}
void CUser::output() {
	cout << this->fullName << endl;
	cout << this->address << endl;
	cout << this->phoneNumber << endl;
	cout << this->emailAddress << endl;
}
