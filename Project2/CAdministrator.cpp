#include "CAdministrator.h"

CAdministrator::CAdministrator(string _username, string _password, string _fullName, string _address, string _phoneNumber, string _emailAddress)
	:CUser(_username, _password, _fullName, _address, _phoneNumber, _emailAddress) {
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
void CAdministrator::searchEmployee() {
}
void CAdministrator::updateEmployee() {
}
void CAdministrator::showInfoEmployee() {
}
