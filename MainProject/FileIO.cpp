#include "FileIO.h"

void file::read::account(std::ifstream & fileIn, User & user) {
	std::string strId, strUsername, strPassword;
	getline(fileIn, strId, ',');
	getline(fileIn, strUsername, ',');
	getline(fileIn, strPassword);
	user.set_id(strId);
	user.set_username(strUsername);
	user.set_password(strPassword);
}
void file::read::info(std::ifstream & fileIn, User & user) {
	std::string strFullName, strAddress, strPhoneNumber, strEmailAddress;
	getline(fileIn, strFullName);
	getline(fileIn, strAddress);
	getline(fileIn, strPhoneNumber);
	getline(fileIn, strEmailAddress);
	user.set_full_name(strFullName);
	user.set_address(strAddress);
	user.set_phone_number(strPhoneNumber);
	user.set_email_address(strEmailAddress);
}

void file::write::account(User user, std::ofstream & fileOut) {
	fileOut << user.get_id() << ',' << user.get_username() << ',' << user.get_password() << std::endl;
}

void file::write::account(User user, std::ofstream & fileOut, AccountType _accountType) {
	switch (_accountType) {
	case AccountType::ADMINISTRATOR:
		fileOut << "AD," << user.get_username() << ',' << user.get_password() << std::endl;
		break;
	case AccountType::EMPLOYEE:
		fileOut << "EM," << user.get_username() << ',' << user.get_password() << std::endl;
		break;
	}
}
void file::write::info(User user, std::ofstream & fileOut) {
	fileOut << user.get_full_name() << std::endl;
	fileOut << user.get_address() << std::endl;
	fileOut << user.get_phone_number() << std::endl;
	fileOut << user.get_email_address() << std::endl;
}
