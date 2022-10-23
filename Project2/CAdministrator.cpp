#include "CAdministrator.h"

CAdministrator::CAdministrator(string _username, string _password, string _fullName, string _address, string _phoneNumber, string _emailAddress)
	:CUser(_username, _password, _fullName, _address, _phoneNumber, _emailAddress) {
}

void CAdministrator::addEmployee() {
	string strUsername;
	textAndBackgroundColor(14, 0);
	cout << endl << "<Them Employees>" << endl;
	textAndBackgroundColor(12, 0);
	cout << "Ten tai khoan khong duoc co khoang cach" << endl;
	textAndBackgroundColor(9, 0);
	cout << "    Nhap ten tai khoan muon them: ";
	textAndBackgroundColor(15, 0);
	cin >> strUsername;
	//check strUsername exists in file Employees.txt
	if (hasAccount<CEmployee>("Resources/Employees.txt", strUsername))
		warning("Username da ton tai!!!");
	else {
		//update file Employees.txt
		ofstream fileUpdated;
		fileUpdated.open("Resources/Employees.txt", ios_base::app);
		fileUpdated << strUsername << "," << "111111" << endl;
		//create a new file and add information to the newly created file
		CUser *userTemp = new CAdministrator;
		ofstream fileOut = createFile(strUsername);
		userTemp->input();
		userTemp->writeInfo(fileOut);
		fileOut.close();
		textAndBackgroundColor(12, 0);
		cout << "Them thanh cong!!!" << endl;
		system("pause");
	}
}

void CAdministrator::eraseEmployee() {

}

