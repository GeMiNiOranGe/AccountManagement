#include "FileManager.hpp"

std::ifstream FileManager::open_file(std::string _username) {
	std::string path = USERS_DIRECTORY + _username + ".txt";
	std::ifstream fin;
	fin.open(path);
	return fin;
}
