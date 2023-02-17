#include "CUser.h"

CUser::CUser(
	std::string _strUsername, std::string _strPassword, std::string _strId, 
	std::string _strFullName, std::string _strAddress, 
	std::string _strPhoneNumber, std::string _strEmailAddress
) {
	this->strUsername = _strUsername;
	this->strPassword = _strPassword;
	this->strPassword = _strId;
	this->strFullName = _strFullName;
	this->strAddress = _strAddress;
	this->strPhoneNumber = _strPhoneNumber;
	this->strEmailAddress = _strEmailAddress;
}
CUser::CUser(const CUser & tempUser) {
	this->strUsername = tempUser.strUsername;
	this->strPassword = tempUser.strPassword;
	this->strPassword = tempUser.strId;
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
const std::string & CUser::getId() {
	return this->strId;
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
void CUser::setId(const std::string & _strId) {
	this->strId = _strId;
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

void CUser::input() {
	std::cin.ignore();
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "    Nhap thong tin tai khoan" << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tNhap ho ten: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	getline(std::cin, this->strFullName);
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tNhap dia chi: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	getline(std::cin, this->strAddress);
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tNhap so dien thoai: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	getline(std::cin, this->strPhoneNumber);
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tNhap dia chi email: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	getline(std::cin, this->strEmailAddress);
}
void CUser::output() {
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tHo ten: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << getFullName() << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tDia chi: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << getAddress() << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tSo dien thoai: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << getPhoneNumber() << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tDia chi email: ";
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << getEmailAddress() << std::endl;
}