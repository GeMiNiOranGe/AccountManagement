#include "CAdministrator.h"

CAdministrator::CAdministrator(string _username, string _password, string _fullName, string _address, string _phoneNumber, string _emailAddress)
	:CUser(_username, _password, _fullName, _address, _phoneNumber, _emailAddress) {
}

void CAdministrator::addEmployee() {
	string strUsernameTemp;
	textAndBackgroundColor(14, 0);
	cout << endl << "<Them Employees>" << endl;
	textAndBackgroundColor(12, 0);
	cout << "Ten tai khoan khong duoc co khoang cach" << endl;
	textAndBackgroundColor(9, 0);
	cout << "    Nhap ten tai khoan muon them: ";
	textAndBackgroundColor(15, 0);
	cin >> strUsernameTemp;
	//check strUsername exists in file Employees.txt
	if (hasAccount<CEmployee>(EMPLOYEES_FILE, strUsernameTemp))
		warning("Username da ton tai!!!");
	else {
		//update file Employees.txt
		ofstream fileUpdated;
		fileUpdated.open(EMPLOYEES_FILE, ios_base::app);
		fileUpdated << strUsernameTemp << "," << "111111" << endl;
		//create a new file and add information to the newly created file
		CUser *userTemp = new CAdministrator;
		ofstream fileOut = createFile(strUsernameTemp);
		userTemp->input();
		userTemp->writeInfo(fileOut);
		fileOut.close();
		textAndBackgroundColor(12, 0);
		cout << "Them thanh cong!!!" << endl;
		system("pause");
	}
}
void CAdministrator::eraseEmployee() {
	string strUsernameTemp, tempFilePath;
	textAndBackgroundColor(14, 0);
	cout << endl << "<Xoa Employees>" << endl;
	textAndBackgroundColor(12, 0);
	cout << "Ten tai khoan khong duoc co khoang cach" << endl;
	textAndBackgroundColor(9, 0);
	cout << "    Nhap ten tai khoan muon xoa: ";
	textAndBackgroundColor(15, 0);
	cin >> strUsernameTemp;
	/*IDEA: 
	step 1: rename Employees.txt into EmployeesTemp.txt
	step 2: create a new Employees.txt
	step 3; write from EmployeesTemp.txt to Employees.txt
	step 4: delete EmployeesTemp.txt */
	int iCount = 0;
	ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE);
	ofstream fileOut(EMPLOYEES_FILE_TEMP);
	while (!fileIn.eof()) {
		CUser *userTemp = new CAdministrator;
		userTemp->readAccount(fileIn);
		if (userTemp->getUsername() != strUsernameTemp) {
			userTemp->writeAccount(fileOut);
		}
		iCount++;
	}
	fileIn.close();
	fileOut.close();
	tempFilePath = "del " + EMPLOYEES_FILE;
	system(tempFilePath.c_str());
	fileIn.open(EMPLOYEES_FILE_TEMP);
	fileOut.open(EMPLOYEES_FILE);
	while (iCount > 1) {
		CUser *userTemp = new CAdministrator;
		userTemp->readAccount(fileIn);
		if (iCount == 3) {
			userTemp->writeAccount(fileOut);
			break;
		}
		userTemp->writeAccount(fileOut);
		iCount--;
	}
	fileIn.close();
	fileOut.close();
	deleteFile(strUsernameTemp);
	tempFilePath = "del " + EMPLOYEES_FILE_TEMP;
	system(tempFilePath.c_str());
	textAndBackgroundColor(12, 0);
	cout << "Xoa thanh cong!!!" << endl;
	system("pause");
}
void CAdministrator::searchEmployee() {
}
void CAdministrator::updateEmployee() {
}
void CAdministrator::showInfoEmployee() {
}
