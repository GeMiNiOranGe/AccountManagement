#include "Administrator.h"

Administrator::Administrator(
	std::string _username, std::string _password, std::string _id,
	std::string _full_name, std::string _address,
	std::string _phone_number, std::string _email_address
) : User(_username, _password, _id, _full_name, _address, _phone_number, _email_address) {
}
//Step 1: update file Employees.txt
//Step 2: create a new file and add information to the newly created file
void Administrator::add_employee(std::string strUsername) {
	//Step 1:
	std::ofstream fileUpdated;
	fileUpdated.open(ACCOUNTS_FILE, std::ios_base::app);
	fileUpdated << "EM," << strUsername << "," << DEFAULT_PASSWORD << std::endl;
	//Step 2: 
	std::ofstream fileOut = createFile(strUsername);
	input();
	file::write::info(*this, fileOut);
	fileOut.close();
}
void Administrator::erase_employee(std::string strUsername) {
	deleteAccount(ACCOUNTS_FILE, strUsername);
	deleteFile(strUsername);
}
//Step 1: load infomation from sourceUserFile
//Step 2: re-open the sourceUserFile again
//Step 3: change the data and overwrite the information from the userTemp
void Administrator::update_info_employee(std::string strSourceUserFile, std::string strInfoUpdated, char cOption) {
	//Step 1:
	std::ifstream fileIn = openFile(strSourceUserFile);
	file::read::info(fileIn, *this);
	fileIn.close();
	//Step 2:
	std::ofstream fileOut;
	fileOut.open((USERS_INFO_FOLDER + strSourceUserFile + ".txt").c_str());
	//Step 3:
	if (cOption == 49)
		User::set_full_name(strInfoUpdated);
	if (cOption == 50)
		User::set_address(strInfoUpdated);
	if (cOption == 51)
		User::set_phone_number(strInfoUpdated);
	if (cOption == 52)
		User::set_email_address(strInfoUpdated);
	file::write::info(*this, fileOut);
	fileOut.close();
}
//Step 1: load username and password into userTemp from file Employees.txt
//Step 2: load information into userTemp from file [username].txt
//Step 3: export information
void Administrator::showInfoAllEmployee() {
	std::ifstream fileIn;
	fileIn.open(ACCOUNTS_FILE);
	//showAnEmployeeInfoElement(Color::LightBlue, "Ten tai khoan", "Ho va ten", "Dia chi", "So dien thoai", "Dia chi email", "| ");
	//showAnEmployeeInfoElement(Color::BrightWhite, "-", "-", "-", "-", "-", "+-", '-');
	while (!fileIn.eof()) {
		//Step 1:
		file::read::account(fileIn, *this);
		//Step 2:
		std::ifstream fileUserInfoTemp = openFile(User::get_username());
		file::read::info(fileUserInfoTemp, *this);
		//Step 3:
		if (User::get_username() != "") {
			//showAnEmployeeInfoElement(Color::BrightWhite, getUsername(), getFullName(), getAddress(), getPhoneNumber(), getEmailAddress(), "| ");
			//showAnEmployeeInfoElement(Color::BrightWhite, "-", "-", "-", "-", "-", "+-", '-');
		}
		fileUserInfoTemp.close();
	}
	fileIn.close();
}

