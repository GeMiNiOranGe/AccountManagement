#include "FileIO.hpp"

void io::File::read_account_from(std::ifstream & _fin, Account & _account) {
	std::string id, username, password;
	getline(_fin, id, ',');
	getline(_fin, username, ',');
	getline(_fin, password);
	_account.set_id(id);
	_account.set_username(username);
	_account.set_password(password);
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

void io::File::write_account_from(Account _account, std::ofstream &_fout) {
	_fout << _account.get_id() << ',' << _account.get_username() << ',' << _account.get_password() << std::endl;
}
void io::File::write_info_from(User _user, std::ofstream &_fout) {
	_fout << _user.get_full_name() << std::endl;
	_fout << _user.get_address() << std::endl;
	_fout << _user.get_phone_number() << std::endl;
	_fout << _user.get_email_address() << std::endl;
}
