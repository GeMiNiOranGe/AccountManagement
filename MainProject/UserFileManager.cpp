#include "UserFileManager.hpp"

std::ifstream UserFileManager::open_file(const std::string &_username) {
	const std::string PATH = USERS_DIRECTORY + _username + ".txt";
	std::ifstream fin;
	fin.open(PATH);
	return fin;
}

void UserFileManager::read_file(std::ifstream &_fin, User &_user) {
	std::string full_name, address, phone_number, email_address;
	getline(_fin, full_name);
	getline(_fin, address);
	getline(_fin, phone_number);
	getline(_fin, email_address);
	_user.set_full_name(full_name);
	_user.set_address(address);
	_user.set_phone_number(phone_number);
	_user.set_email_address(email_address);
}
void UserFileManager::write_file(const User &_user, std::ofstream &_fout) {
	_fout << _user.get_full_name() << std::endl;
	_fout << _user.get_address() << std::endl;
	_fout << _user.get_phone_number() << std::endl;
	_fout << _user.get_email_address() << std::endl;
}
