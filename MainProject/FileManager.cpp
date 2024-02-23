#include "FileManager.hpp"

std::ifstream FileManager::open_file(const std::string &_username) {
	const std::string PATH = USERS_DIRECTORY + _username + ".txt";
	std::ifstream fin;
	fin.open(PATH);
	return fin;
}

void FileManager::read_file(std::ifstream &_fin, User &_user) {
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
void FileManager::read_file(std::ifstream &_fin, Account &_account) {
	std::string _id, _username, _password;
	getline(_fin, _id, ',');
	getline(_fin, _username, ',');
	getline(_fin, _password);
	_account.set_id(_id);
	_account.set_username(_username);
	_account.set_password(_password);
}

void FileManager::write_file(const User &_user, std::ofstream &_fout) {
	_fout << _user.get_full_name() << std::endl;
	_fout << _user.get_address() << std::endl;
	_fout << _user.get_phone_number() << std::endl;
	_fout << _user.get_email_address() << std::endl;
}
void FileManager::write_file(const Account &_account, std::ofstream &_fout) {
	_fout << _account.get_id() << ','
		<< _account.get_username() << ','
		<< _account.get_password() << std::endl;
}
