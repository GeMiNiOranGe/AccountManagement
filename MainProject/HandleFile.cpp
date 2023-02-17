#include "HandleFile.h"

void handleFile::read::account(CUser & userTemp, std::ifstream & fileIn) {
	std::string _strId, _strUsername, _strPassword;
	getline(fileIn, _strId, ',');
	getline(fileIn, _strUsername, ',');
	getline(fileIn, _strPassword);
	userTemp.setUsername(_strUsername);
	userTemp.setPassword(_strPassword);
	userTemp.setId(_strId);
}
void handleFile::read::info(CUser & userTemp, std::ifstream & fileIn) {
	std::string _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress;
	getline(fileIn, _strFullName);
	getline(fileIn, _strAddress);
	getline(fileIn, _strPhoneNumber);
	getline(fileIn, _strEmailAddress);
	userTemp.setFullName(_strFullName);
	userTemp.setAddress(_strAddress);
	userTemp.setPhoneNumber(_strPhoneNumber);
	userTemp.setEmailAddress(_strEmailAddress);
}

void handleFile::write::account(CUser & userTemp, std::ofstream & fileOut) {
	fileOut << userTemp.getId() << ',' << userTemp.getUsername() << ',' << userTemp.getPassword() << std::endl;
}

void handleFile::write::account(CUser & userTemp, std::ofstream & fileOut, handleFile::AccountType _accountType) {
	switch (_accountType) {
	case handleFile::AccountType::Administrator:
		fileOut << "AD," << userTemp.getUsername() << ',' << userTemp.getPassword() << std::endl;
		break;
	case handleFile::AccountType::Employee:
		fileOut << "EM," << userTemp.getUsername() << ',' << userTemp.getPassword() << std::endl;
		break;
	//case handleFile::AccountType::None:
	//	break;
	//default:
	//	break;
	}
}
void handleFile::write::info(CUser & userTemp, std::ofstream & fileOut) {
	fileOut << userTemp.getFullName() << std::endl;
	fileOut << userTemp.getAddress() << std::endl;
	fileOut << userTemp.getPhoneNumber() << std::endl;
	fileOut << userTemp.getEmailAddress() << std::endl;
}
