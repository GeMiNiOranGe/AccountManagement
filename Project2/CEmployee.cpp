#include "CEmployee.h"

CEmployee::CEmployee(string _strUsername, string _strPassword, string _strFullName, string _strAddress, string _strPhoneNumber, string _strEmailAddress)
	:CUser(_strUsername, _strPassword, _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress) {
}

void CEmployee::changePassword() {
}
