#pragma once
#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

class Convert {
public:
    static std::wstring to_wstring(const std::string);
    static char * to_char(const std::string);
};

#endif  // end CONVERT_HPP
