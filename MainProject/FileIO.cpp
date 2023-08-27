#include "FileIO.h"

void io::File::read_account_from(std::ifstream & _fin, User & _user) {
	std::string id, username, password;
	getline(_fin, id, ',');
	getline(_fin, username, ',');
	getline(_fin, password);
	_user.set_id(id);
	_user.set_username(username);
	_user.set_password(password);
}
void io::File::read_info_from(std::ifstream & _fin, User & _user) {
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

void io::File::write_account_from(User _user, std::ofstream &_fout) {
	_fout << _user.get_id() << ',' << _user.get_username() << ',' << _user.get_password() << std::endl;
}
void io::File::write_info_from(User _user, std::ofstream &_fout) {
	_fout << _user.get_full_name() << std::endl;
	_fout << _user.get_address() << std::endl;
	_fout << _user.get_phone_number() << std::endl;
	_fout << _user.get_email_address() << std::endl;
}
