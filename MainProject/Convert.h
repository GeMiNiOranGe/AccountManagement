#ifndef CONVERT_H
#define CONVERT_H
#pragma once

#include <string>

class Convert {
public:
	static std::wstring to_wstring(const std::string);
	static char * to_char(const std::string);
};

#endif // end CONVERT_H