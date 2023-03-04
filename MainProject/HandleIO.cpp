#include "HandleIO.h"

void file::read::account(CUser & _user, std::ifstream & fileIn) {
	std::string _strId, _strUsername, _strPassword;
	getline(fileIn, _strId, ',');
	getline(fileIn, _strUsername, ',');
	getline(fileIn, _strPassword);
	_user.setUsername(_strUsername);
	_user.setPassword(_strPassword);
	_user.setId(_strId);
}
void file::read::info(CUser & _user, std::ifstream & fileIn) {
	std::string _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress;
	getline(fileIn, _strFullName);
	getline(fileIn, _strAddress);
	getline(fileIn, _strPhoneNumber);
	getline(fileIn, _strEmailAddress);
	_user.setFullName(_strFullName);
	_user.setAddress(_strAddress);
	_user.setPhoneNumber(_strPhoneNumber);
	_user.setEmailAddress(_strEmailAddress);
}

void file::write::account(CUser _user, std::ofstream & fileOut) {
	fileOut << _user.getId() << ',' << _user.getUsername() << ',' << _user.getPassword() << std::endl;
}

void file::write::account(CUser _user, std::ofstream & fileOut, file::AccountType _accountType) {
	switch (_accountType) {
	case file::AccountType::Administrator:
		fileOut << "AD," << _user.getUsername() << ',' << _user.getPassword() << std::endl;
		break;
	case file::AccountType::Employee:
		fileOut << "EM," << _user.getUsername() << ',' << _user.getPassword() << std::endl;
		break;
	//case file::AccountType::None:
	//	break;
	//default:
	//	break;
	}
}
void file::write::info(CUser _user, std::ofstream & fileOut) {
	fileOut << _user.getFullName() << std::endl;
	fileOut << _user.getAddress() << std::endl;
	fileOut << _user.getPhoneNumber() << std::endl;
	fileOut << _user.getEmailAddress() << std::endl;
}
