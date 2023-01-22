#include "CUser.h"

CUser::CUser(string _strUsername, string _strPassword, string _strFullName, string _strAddress, string _strPhoneNumber, string _strEmailAddress) {
	this->strUsername = _strUsername;
	this->strPassword = _strPassword;
	this->strFullName = _strFullName;
	this->strAddress = _strAddress;
	this->strPhoneNumber = _strPhoneNumber;
	this->strEmailAddress = _strEmailAddress;
}
CUser::CUser(const CUser & tempUser) {
	this->strUsername = tempUser.strUsername;
	this->strPassword = tempUser.strPassword;
	this->strFullName = tempUser.strFullName;
	this->strAddress = tempUser.strAddress;
	this->strPhoneNumber = tempUser.strPhoneNumber;
	this->strEmailAddress = tempUser.strEmailAddress;
}
CUser::~CUser() {
}

const string& CUser::getUsername() {
	return this->strUsername;
}
const string& CUser::getPassword() {
	return this->strPassword;
}
const string& CUser::getFullName() {
	return this->strFullName;
}
const string& CUser::getAddress() {
	return this->strAddress;
}
const string& CUser::getPhoneNumber() {
	return this->strPhoneNumber;
}
const string& CUser::getEmailAddress() {
	return this->strEmailAddress;
}

void CUser::setUsername(const string& _strUsername) {
	this->strUsername = _strUsername;
}
void CUser::setPassword(const string& _strPassword) {
	this->strPassword = _strPassword;
}
void CUser::setFullName(const string& _strFullName) {
	this->strFullName = _strFullName;
}
void CUser::setAddress(const string& _strAddress) {
	this->strAddress = _strAddress;
}
void CUser::setPhoneNumber(const string& _strPhoneNumber) {
	this->strPhoneNumber = _strPhoneNumber;
}
void CUser::setEmailAddress(const string& _strEmailAddress) {
	this->strEmailAddress = _strEmailAddress;
}

void CUser::readAccount(ifstream& fileIn) {
	getline(fileIn, this->strUsername, ',');
	getline(fileIn, this->strPassword);
}
void CUser::writeAccount(ofstream& fileOut) {
	fileOut << this->strUsername << ',';
	fileOut << this->strPassword << endl;
}
void CUser::readInfo(ifstream& fileIn) {
	getline(fileIn, this->strFullName);
	getline(fileIn, this->strAddress);
	getline(fileIn, this->strPhoneNumber);
	getline(fileIn, this->strEmailAddress);
}
void CUser::writeInfo(ofstream& fileOut) {
	fileOut << this->strFullName << endl;
	fileOut << this->strAddress << endl;
	fileOut << this->strPhoneNumber << endl;
	fileOut << this->strEmailAddress << endl;
}

void CUser::input() {
	cin.ignore();
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "    Nhap thong tin tai khoan" << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tNhap ho ten: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(cin, this->strFullName);
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tNhap dia chi: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(cin, this->strAddress);
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tNhap so dien thoai: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(cin, this->strPhoneNumber);
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tNhap dia chi email: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(cin, this->strEmailAddress);
}
void CUser::output() {
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tHo ten: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << getFullName() << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tDia chi: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << getAddress() << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tSo dien thoai: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << getPhoneNumber() << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tDia chi email: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << getEmailAddress() << endl;
}
