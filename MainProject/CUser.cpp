#include "CUser.h"

CUser::CUser(std::string _strUsername, std::string _strPassword, std::string _strFullName,
	std::string _strAddress, std::string _strPhoneNumber, std::string _strEmailAddress) {
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

const std::string & CUser::getUsername() {
	return this->strUsername;
}
const std::string & CUser::getPassword() {
	return this->strPassword;
}
const std::string & CUser::getFullName() {
	return this->strFullName;
}
const std::string & CUser::getAddress() {
	return this->strAddress;
}
const std::string & CUser::getPhoneNumber() {
	return this->strPhoneNumber;
}
const std::string & CUser::getEmailAddress() {
	return this->strEmailAddress;
}

void CUser::setUsername(const std::string & _strUsername) {
	this->strUsername = _strUsername;
}
void CUser::setPassword(const std::string & _strPassword) {
	this->strPassword = _strPassword;
}
void CUser::setFullName(const std::string & _strFullName) {
	this->strFullName = _strFullName;
}
void CUser::setAddress(const std::string & _strAddress) {
	this->strAddress = _strAddress;
}
void CUser::setPhoneNumber(const std::string & _strPhoneNumber) {
	this->strPhoneNumber = _strPhoneNumber;
}
void CUser::setEmailAddress(const std::string & _strEmailAddress) {
	this->strEmailAddress = _strEmailAddress;
}

//void CUser::readAccount(std::ifstream & fileIn) {
//	getline(fileIn, this->strUsername, ',');
//	getline(fileIn, this->strPassword);
//}
//void CUser::writeAccount(std::ofstream & fileOut) {
//	fileOut << this->strUsername << ',';
//	fileOut << this->strPassword << std::endl;
//}
//void CUser::readInfo(std::ifstream & fileIn) {
//	getline(fileIn, this->strFullName);
//	getline(fileIn, this->strAddress);
//	getline(fileIn, this->strPhoneNumber);
//	getline(fileIn, this->strEmailAddress);
//}
//void CUser::writeInfo(std::ofstream & fileOut) {
//	fileOut << this->strFullName << std::endl;
//	fileOut << this->strAddress << std::endl;
//	fileOut << this->strPhoneNumber << std::endl;
//	fileOut << this->strEmailAddress << std::endl;
//}

void CUser::input() {
	std::cin.ignore();
	textAndBackgroundColor(color::LightYellow, color::Black);
	std::cout << "    Nhap thong tin tai khoan" << std::endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tNhap ho ten: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(std::cin, this->strFullName);
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tNhap dia chi: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(std::cin, this->strAddress);
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tNhap so dien thoai: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(std::cin, this->strPhoneNumber);
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tNhap dia chi email: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	getline(std::cin, this->strEmailAddress);
}
void CUser::output() {
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tHo ten: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	std::cout << getFullName() << std::endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tDia chi: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	std::cout << getAddress() << std::endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tSo dien thoai: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	std::cout << getPhoneNumber() << std::endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	std::cout << "\tDia chi email: ";
	textAndBackgroundColor(color::BrightWhite, color::Black);
	std::cout << getEmailAddress() << std::endl;
}