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
	ofstream fileOut = createFile(strUsername);
	input();
	writeInfo(fileOut);
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
		readAccount(fileIn);
		if (getUsername() != strUsername && getUsername() != "")
			writeAccount(fileOut);
	}
	fileOut.close();
	fileIn.close();
	//Step 4:
	deleteFile(strUsername);
	system(employeeFileRenamed.insert(0, "del ").c_str());
}
//Step 1: load infomation from sourceUserFile
//Step 2: re-open the sourceUserFile again
//Step 3: change the data and overwrite the information from the userTemp
void CAdministrator::updateInfoEmployee(string strSourceUserFile, string strInfoUpdated, char cOption) {
	//Step 1:
	ifstream fileIn = openFile(strSourceUserFile);
	readInfo(fileIn);
	fileIn.close();
	//Step 2:
	ofstream fileOut;
	fileOut.open((USER_INFO_FOLDER + strSourceUserFile + ".txt").c_str());
	//Step 3:
	if (cOption == 49)
		setFullName(strInfoUpdated);
	if (cOption == 50)
		setAddress(strInfoUpdated);
	if (cOption == 51)
		setPhoneNumber(strInfoUpdated);
	if (cOption == 52)
		setEmailAddress(strInfoUpdated);
	writeInfo(fileOut);
	fileOut.close();
}
//Step 1: load username and password into userTemp from file Employees.txt
//Step 2: load information into userTemp from file [username].txt
//Step 3: export information
void CAdministrator::showInfoAllEmployee() {
	ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE);
	showAnEmployeeInfoElement(9,"Ten tai khoan", "Ho va ten", "Dia chi", "So dien thoai", "Dia chi email", "| ");
	showAnEmployeeInfoElement(15,"-", "-", "-", "-", "-", "+-", '-');
	while (!fileIn.eof()) {
		//Step 1:
		readAccount(fileIn);
		//Step 2:
		ifstream fileUserInfoTemp = openFile(getUsername());
		readInfo(fileUserInfoTemp);
		//Step 3:
		if (getUsername() != "") {
			showAnEmployeeInfoElement(15, getUsername(), getFullName(), getAddress(), getPhoneNumber(), getEmailAddress(), "| ");
			showAnEmployeeInfoElement(15, "-", "-", "-", "-", "-", "+-", '-');
		}
		fileUserInfoTemp.close();
	}
	fileIn.close();
}

