#include "convert.hpp"

std::wstring Convert::to_wstring(const std::string _string) {
    return std::wstring(_string.begin(), _string.end());
}

char * Convert::to_char(const std::string _string) {
    char * p_cOutput = new char[_string.length() + 1];
    strcpy_s(p_cOutput, _string.length() + 1, _string.c_str());
    return p_cOutput;
}
