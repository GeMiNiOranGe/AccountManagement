#include "CAdministrator.h"

CAdministrator::CAdministrator(std::string _strUsername, std::string _strPassword, std::string _strFullName,
	std::string _strAddress, std::string _strPhoneNumber, std::string _strEmailAddress)
	:CUser(_strUsername, _strPassword, _strFullName, _strAddress, _strPhoneNumber, _strEmailAddress) {
}
//Step 1: update file Employees.txt
//Step 2: create a new file and add information to the newly created file
void CAdministrator::addEmployee(std::string strUsername) {
	//Step 1:
	std::ofstream fileUpdated;
	fileUpdated.open(EMPLOYEES_FILE, std::ios_base::app);
	fileUpdated << strUsername << "," << "111111" << std::endl;
	//Step 2: 
	std::ofstream fileOut = createFile(strUsername);
	input();
	handleFile::write::info(*this, fileOut);
	fileOut.close();
}
void CAdministrator::eraseEmployee(std::string strUsername) {
	deleteAccount(EMPLOYEES_FILE, strUsername);
	deleteFile(strUsername);
}
//Step 1: load infomation from sourceUserFile
//Step 2: re-open the sourceUserFile again
//Step 3: change the data and overwrite the information from the userTemp
void CAdministrator::updateInfoEmployee(std::string strSourceUserFile, std::string strInfoUpdated, char cOption) {
	//Step 1:
	std::ifstream fileIn = openFile(strSourceUserFile);
	handleFile::read::info(*this, fileIn);
	fileIn.close();
	//Step 2:
	std::ofstream fileOut;
	fileOut.open((USERS_INFO_FOLDER + strSourceUserFile + ".txt").c_str());
	//Step 3:
	if (cOption == 49)
		setFullName(strInfoUpdated);
	if (cOption == 50)
		setAddress(strInfoUpdated);
	if (cOption == 51)
		setPhoneNumber(strInfoUpdated);
	if (cOption == 52)
		setEmailAddress(strInfoUpdated);
	handleFile::write::info(*this, fileOut);
	fileOut.close();
}
//Step 1: load username and password into userTemp from file Employees.txt
//Step 2: load information into userTemp from file [username].txt
//Step 3: export information
void CAdministrator::showInfoAllEmployee() {
	std::ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE);
	showAnEmployeeInfoElement(color::LightBlue, "Ten tai khoan", "Ho va ten", "Dia chi", "So dien thoai", "Dia chi email", "| ");
	showAnEmployeeInfoElement(color::BrightWhite, "-", "-", "-", "-", "-", "+-", '-');
	while (!fileIn.eof()) {
		//Step 1:
		handleFile::read::account(*this, fileIn);
		//Step 2:
		std::ifstream fileUserInfoTemp = openFile(getUsername());
		handleFile::read::info(*this, fileUserInfoTemp);
		//Step 3:
		if (getUsername() != "") {
			showAnEmployeeInfoElement(color::BrightWhite, getUsername(), getFullName(), getAddress(), getPhoneNumber(), getEmailAddress(), "| ");
			showAnEmployeeInfoElement(color::BrightWhite, "-", "-", "-", "-", "-", "+-", '-');
		}
		fileUserInfoTemp.close();
	}
	fileIn.close();
}

