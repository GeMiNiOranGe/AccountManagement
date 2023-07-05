#include "HandleMain.h"

std::ofstream createFile(std::string strUsernameFile) {
	std::string filePath = USERS_INFO_FOLDER + strUsernameFile + ".txt";
	std::ofstream fileTemp(filePath);
	return fileTemp;
}
std::ifstream openFile(std::string strUsernameFile) {
	std::string filePath = USERS_INFO_FOLDER + strUsernameFile + ".txt";
	std::ifstream fileTemp;
	fileTemp.open(filePath);
	return fileTemp;
}
void deleteFile(std::string strUsernameFile) {
	std::string filePath = "del " + USERS_INFO_FOLDER + strUsernameFile + ".txt";
	system(filePath.c_str());
}

void deleteAccount(std::string strSourceFile, std::string strUsername) {
	User userTemp;
	//Step 1:
	std::string employeeFileRenamed = strSourceFile;
	rename(strSourceFile.c_str(), employeeFileRenamed.insert(employeeFileRenamed.size() - 4, "Temp").c_str());
	//Step 2:
	std::ofstream fileOut(strSourceFile);
	std::ifstream fileIn;
	fileIn.open(employeeFileRenamed.c_str());
	//Step 3:
	while (!fileIn.eof()) {
		file::read::account(fileIn, userTemp);
		if (userTemp.get_username() != strUsername && userTemp.get_username() != "")
			file::write::account(userTemp, fileOut);
	}
	fileOut.close();
	fileIn.close();
	//Step 4:
	system(employeeFileRenamed.insert(0, "del ").c_str());
}

void showAccountInfo(std::string strUsername) {
	User userTemp;
	std::ifstream fileIn = openFile(strUsername);
	file::read::info(fileIn, userTemp);
	userTemp.output();
	fileIn.close();
}

bool hasUsername(std::string strSourceFile, std::string strUsername) {
	std::ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		User userTemp;
		file::read::account(fileIn, userTemp);
		if (strUsername == userTemp.get_username()) {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
bool hasAccount(std::string strSourceFile, std::string strUsername, std::string strPassword) {
	std::ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		User userTemp;
		file::read::account(fileIn, userTemp);
		if (strUsername == userTemp.get_username() && strPassword == userTemp.get_password() && userTemp.get_username() != "" && userTemp.get_password() != "") {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}

std::string checkTypeAccount(std::string strUsername, std::string strPassword) {
	std::ifstream fileIn;
	fileIn.open(ACCOUNTS_FILE.c_str());
	while (!fileIn.eof()) {
		User userTemp;
		file::read::account(fileIn, userTemp);
		if (userTemp.get_id() == "AD" && userTemp.get_username() == strUsername && userTemp.get_password() == strPassword) {
			fileIn.close();
			return "admin";
		}
		if (userTemp.get_id() == "EM" && userTemp.get_username() == strUsername && userTemp.get_password() == strPassword) {
			fileIn.close();
			return "employee";
		}
	}
	return "";
}
