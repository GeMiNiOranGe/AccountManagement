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

bool hasAccount(string strSourceFile, string strUsername) {
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
