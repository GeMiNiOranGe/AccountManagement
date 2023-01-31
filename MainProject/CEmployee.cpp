#include "CEmployee.h"

CEmployee::CEmployee(std::string _strUsername, std::string _strPassword, std::string _strFullName,
	std::string _strAddress, std::string _strPhoneNumber, std::string _strEmailAddress)
	:CUser(_strUsername, _strPassword, _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress) {
}

bool CEmployee::isSuccessChangePass(std::string strUsername, std::string strCurrentPass, std::string strNewPass, std::string strConfirmNewPass) {
	std::ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE.c_str());
	while (!fileIn.eof()) {
		readAccount(fileIn);
		if (getUsername() == strUsername && getPassword() == strCurrentPass && strNewPass == strConfirmNewPass) {
			setPassword(strNewPass);
			fileIn.close();
			deleteAccount(EMPLOYEES_FILE, strUsername);
			std::ofstream fileOut;
			fileOut.open(EMPLOYEES_FILE.c_str(), std::ios_base::app);
			writeAccount(fileOut);
			fileOut.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
