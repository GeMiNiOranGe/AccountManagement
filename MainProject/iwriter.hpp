#pragma once
#ifndef IWRITER_HPP
#define IWRITER_HPP

#include <fstream>

class IWriter {
public:
	virtual void write_file(std::ofstream & _fout) = 0;
};

#endif // end IWRITER_HPP