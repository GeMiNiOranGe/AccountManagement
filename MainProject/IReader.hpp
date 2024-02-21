#pragma once
#ifndef IREADER_HPP
#define IREADER_HPP

#include <fstream>

class IReader {
public:
	virtual void read_file(std::ifstream & _fin) = 0;
};

#endif // end IREADER_HPP