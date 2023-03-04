#include "CEmployee.h"

CEmployee::CEmployee(
	std::string _strUsername, std::string _strPassword, std::string _strId,
	std::string _strFullName, std::string _strAddress,
	std::string _strPhoneNumber, std::string _strEmailAddress
) : CUser(_strUsername, _strPassword, _strId, _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress) {
}

bool CEmployee::isSuccessChangePass(std::string strUsername, std::string strCurrentPass, std::string strNewPass, std::string strConfirmNewPass) {
	std::ifstream fileIn;
	fileIn.open(ACCOUNTS_FILE.c_str());
	while (!fileIn.eof()) {
		file::read::account(*this, fileIn);
		if (getUsername() == strUsername && getPassword() == strCurrentPass && strNewPass == strConfirmNewPass) {
			setPassword(strNewPass);
			fileIn.close();
			deleteAccount(ACCOUNTS_FILE, strUsername);
			std::ofstream fileOut;
			fileOut.open(ACCOUNTS_FILE.c_str(), std::ios_base::app);
			file::write::account(*this, fileOut, file::AccountType::Employee);
			fileOut.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
