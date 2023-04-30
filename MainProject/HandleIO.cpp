#include "HandleIO.h"

void file::read::account(CUser & user, std::ifstream & fileIn) {
	std::string strId, strUsername, strPassword;
	getline(fileIn, strId, ',');
	getline(fileIn, strUsername, ',');
	getline(fileIn, strPassword);
	user.setId(strId);
	user.setUsername(strUsername);
	user.setPassword(strPassword);
}
void file::read::info(CUser & user, std::ifstream & fileIn) {
	std::string strFullName, strAddress, strPhoneNumber, strEmailAddress;
	getline(fileIn, strFullName);
	getline(fileIn, strAddress);
	getline(fileIn, strPhoneNumber);
	getline(fileIn, strEmailAddress);
	user.setFullName(strFullName);
	user.setAddress(strAddress);
	user.setPhoneNumber(strPhoneNumber);
	user.setEmailAddress(strEmailAddress);
}

void file::write::account(CUser user, std::ofstream & fileOut) {
	fileOut << user.getId() << ',' << user.getUsername() << ',' << user.getPassword() << std::endl;
}

void file::write::account(CUser user, std::ofstream & fileOut, file::AccountType _accountType) {
	switch (_accountType) {
	case file::AccountType::Administrator:
		fileOut << "AD," << user.getUsername() << ',' << user.getPassword() << std::endl;
		break;
	case file::AccountType::Employee:
		fileOut << "EM," << user.getUsername() << ',' << user.getPassword() << std::endl;
		break;
	//case file::AccountType::None:
	//	break;
	//default:
	//	break;
	}
}
void file::write::info(CUser user, std::ofstream & fileOut) {
	fileOut << user.getFullName() << std::endl;
	fileOut << user.getAddress() << std::endl;
	fileOut << user.getPhoneNumber() << std::endl;
	fileOut << user.getEmailAddress() << std::endl;
}
