#include "CAdministrator.h"

CAdministrator::CAdministrator(string _strUsername, string _strPassword, string _strFullName, string _strAddress, string _strPhoneNumber, string _strEmailAddress)
	:CUser(_strUsername, _strPassword, _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress) {
}
//Step 1: update file Employees.txt
//Step 2: create a new file and add information to the newly created file
void CAdministrator::addEmployee(string strUsername) {
	//Step 1:
	ofstream fileUpdated;
	fileUpdated.open(EMPLOYEES_FILE, ios_base::app);
	fileUpdated << strUsername << "," << "111111" << endl;
	//Step 2: 
	CUser userTemp;
	ofstream fileOut = createFile(strUsername);
	userTemp.input();
	userTemp.writeInfo(fileOut);
	fileOut.close();
}
//Step 1: rename Employees.txt into EmployeesTemp.txt
//Step 2: create a new Employees.txt and open the file is renamed (EmployeesTemp.txt)
//Step 3: write from the file is renamed (EmployeesTemp.txt) to Employees.txt and don't write the employee want to delete
//Step 4: delete the file is renamed (delete EmployeesTemp.txt) and the employee you want to delete has been deleted
void CAdministrator::eraseEmployee(string strUsername) {
	//Step 1:
	string employeeFileRenamed = EMPLOYEES_FILE;
	rename(EMPLOYEES_FILE.c_str(), employeeFileRenamed.insert(employeeFileRenamed.size() - 4, "Temp").c_str());
	//Step 2:
	ofstream fileOut(EMPLOYEES_FILE);
	ifstream fileIn;
	fileIn.open(employeeFileRenamed.c_str());
	//Step 3:
	while (!fileIn.eof()) {
		CUser userTemp;
		userTemp.readAccount(fileIn);
		if (userTemp.getUsername() != strUsername && userTemp.getUsername() != "")
			userTemp.writeAccount(fileOut);
	}
	fileOut.close();
	fileIn.close();
	//Step 4:
	deleteFile(strUsername);
	system(employeeFileRenamed.insert(0, "del ").c_str());
}
void CAdministrator::updateEmployee() {

}
//Step 1: load username and password into userTemp from file Employees.txt
//Step 2: load information into userTemp from file [username].txt
//Step 3: export information
void CAdministrator::showInfoAllEmployee() {
	ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE);
	CUser userTemp;
	while (!fileIn.eof()) {
		//Step 1:
		userTemp.readAccount(fileIn);
		//Step 2:
		ifstream fileUserInfoTemp = openFile(userTemp.getUsername());
		userTemp.readInfo(fileUserInfoTemp);
		//Step 3:
		if (userTemp.getUsername() != "") {
			cout << "Ten tai khoan: " << userTemp.getUsername() << endl;
			userTemp.output();
		}
		fileUserInfoTemp.close();
		cout << endl;
	}
	fileIn.close();
}

