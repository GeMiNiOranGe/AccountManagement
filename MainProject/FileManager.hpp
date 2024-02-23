#pragma once
#ifndef FILEMANAGEMENT_HPP
#define FILEMANAGEMENT_HPP

#include <fstream>

#include "Config.hpp"

class FileManager {
public:
	static std::ifstream open_file(std::string _username);
};

#endif // end FILEMANAGEMENT_HPP