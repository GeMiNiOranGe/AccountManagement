#include "HandleMain.h"

ofstream createFile(string fileName) {
	string filePath = USER_INFO_FOLDER + fileName + ".txt";
	ofstream fileTemp(filePath);
	return fileTemp;
}
ifstream openFile(string fileName) {
	string filePath = USER_INFO_FOLDER + fileName + ".txt";
	ifstream fileTemp;
	fileTemp.open(filePath);
	return fileTemp;
}
void deleteFile(string fileName) {
	string filePath = "del " + USER_INFO_FOLDER + fileName + ".txt";
	system(filePath.c_str());
}
