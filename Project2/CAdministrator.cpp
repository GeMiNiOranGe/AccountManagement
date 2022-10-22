#include "CAdministrator.h"

CAdministrator::CAdministrator(string _username, string _password, string _fullName, string _address, string _phoneNumber, string _emailAddress)
	:CUser(_username, _password, _fullName, _address, _phoneNumber, _emailAddress) {
}

void CAdministrator::addEmployee(string strUsername, string strPassword) {
	textAndBackgroundColor(13, 0);
	cout << "Nhap ten tai khoan muon them: ";
	textAndBackgroundColor(15, 0);
	cin >> strUsername;
	if (hasAccount<CEmployee>("Resources/Employees.txt", strUsername))
		chooseWrong("Username da ton tai!!!");
	else {
		CUser *userTemp = new CAdministrator;
		ofstream fileOut = userTemp->createFile(strUsername);
		textAndBackgroundColor(14, 0);
		cout << "Nhap thong tin tai khoan" << endl;
		userTemp->input();
		userTemp->writeInfo(fileOut);
		fileOut.close();
		textAndBackgroundColor(12, 0);
		cout << "Them thanh cong!!!" << endl;
		system("pause");
	}
}

