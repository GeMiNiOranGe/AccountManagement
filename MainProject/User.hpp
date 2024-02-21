#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <string>
// #include "IReader.hpp"
// #include "IWriter.hpp"

class User /* :public IReader, public IWriter */ {
public:
	User(std::string _id = "", std::string _full_name = "", std::string _address = "", std::string _phone_number = "", std::string _email_address = "");
	User(const User &);
	~User();

	std::string * get_properties();

	const std::string & get_id();
	const std::string & get_full_name();
	const std::string & get_address();
	const std::string & get_phone_number();
	const std::string & get_email_address();

	void set_id(const std::string &);
	void set_full_name(const std::string &);
	void set_address(const std::string &);
	void set_phone_number(const std::string &);
	void set_email_address(const std::string &);

	// void read_file(std::ifstream & _fin) override;
	// void write_file(std::ofstream & _fout) override;

private:
	std::string id; // e.g: Id: EM82Na5s7d, EM is Employee, 82Na5s7d is base64 code 
	std::string full_name;
	std::string address;
	std::string phone_number;
	std::string email_address;
};

#endif // end USER_HPP