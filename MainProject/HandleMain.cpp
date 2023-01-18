#include "HandleMain.h"

ofstream createFile(string strUsernameFile) {
	string filePath = USER_INFO_FOLDER + strUsernameFile + ".txt";
	ofstream fileTemp(filePath);
	return fileTemp;
}
ifstream openFile(string strUsernameFile) {
	string filePath = USER_INFO_FOLDER + strUsernameFile + ".txt";
	ifstream fileTemp;
	fileTemp.open(filePath);
	return fileTemp;
}
void deleteFile(string strUsernameFile) {
	string filePath = "del " + USER_INFO_FOLDER + strUsernameFile + ".txt";
	system(filePath.c_str());
}

void deleteAccount(string strSourceFile, string strUsername) {
	CUser userTemp;
	//Step 1:
	string employeeFileRenamed = strSourceFile;
	rename(strSourceFile.c_str(), employeeFileRenamed.insert(employeeFileRenamed.size() - 4, "Temp").c_str());
	//Step 2:
	ofstream fileOut(strSourceFile);
	ifstream fileIn;
	fileIn.open(employeeFileRenamed.c_str());
	//Step 3:
	while (!fileIn.eof()) {
		userTemp.readAccount(fileIn);
		if (userTemp.getUsername() != strUsername && userTemp.getUsername() != "")
			userTemp.writeAccount(fileOut);
	}
	fileOut.close();
	fileIn.close();
	//Step 4:
	system(employeeFileRenamed.insert(0, "del ").c_str());
}

void showAccountInfo(string strUsername) {
	CUser userTemp;
	ifstream fileIn = openFile(strUsername);
	userTemp.readInfo(fileIn);
	userTemp.output();
	fileIn.close();
}

bool hasUsername(string strSourceFile, string strUsername) {
	ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser userTemp;
		userTemp.readAccount(fileIn);
		if (strUsername == userTemp.getUsername()) {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
bool hasAccount(string strSourceFile, string strUsername, string strPassword) {
	ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser userTemp;
		userTemp.readAccount(fileIn);
		if (strUsername == userTemp.getUsername() && strPassword == userTemp.getPassword() && userTemp.getUsername() != "" && userTemp.getPassword() != "") {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
