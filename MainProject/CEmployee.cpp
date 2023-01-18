#include "CEmployee.h"

CEmployee::CEmployee(string _strUsername, string _strPassword, string _strFullName, string _strAddress, string _strPhoneNumber, string _strEmailAddress)
	:CUser(_strUsername, _strPassword, _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress) {
}

bool CEmployee::isSuccessChangePass(string strUsername, string strCurrentPass, string strNewPass, string strConfirmNewPass) {
	ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE.c_str());
	while (!fileIn.eof()) {
		readAccount(fileIn);
		if (getUsername() == strUsername && getPassword() == strCurrentPass && strNewPass == strConfirmNewPass) {
			setPassword(strNewPass);
			fileIn.close();
			deleteAccount(EMPLOYEES_FILE, strUsername);
			ofstream fileOut;
			fileOut.open(EMPLOYEES_FILE.c_str(), ios_base::app);
			writeAccount(fileOut);
			fileOut.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
