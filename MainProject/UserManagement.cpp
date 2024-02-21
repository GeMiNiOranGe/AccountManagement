#include "UserManagement.hpp"

UserManagement::UserManagement(const User &_user) {
	this->user = _user;
}

const User &UserManagement::get_user() {
    return this->user;
}

void UserManagement::read_file(std::ifstream &_fin) {
    std::string full_name, address, phone_number, email_address;
	getline(_fin, full_name);
	getline(_fin, address);
	getline(_fin, phone_number);
	getline(_fin, email_address);
	this->user.set_full_name(full_name);
	this->user.set_address(address);
	this->user.set_phone_number(phone_number);
	this->user.set_email_address(email_address);
}
void UserManagement::write_file(std::ofstream &_fout) {
	_fout << this->user.get_full_name() << std::endl;
	_fout << this->user.get_address() << std::endl;
	_fout << this->user.get_phone_number() << std::endl;
	_fout << this->user.get_email_address() << std::endl;
}

void UserManagement::create_account(std::string _username) {
	Account::create_a_new(_username);
	// Create a new file and add information to the newly created file
	std::ofstream fout = create_file(_username);
	// User user;
	// console::read_info(user);
	// user.write_file(fout);

	console::read_info(this->user);
	this->write_file(fout);
	
	fout.close();
}
void UserManagement::delete_account(std::string _username) {
	Account::delete_by(_username);
	delete_file(_username);
}
void UserManagement::update_information_user(std::string _username, std::string _info_updated, char _option) {
	// Load infomation from _username file
	std::ifstream fin = open_file(_username);
	// User user;
	// user.read_file(fin);

	this->read_file(fin);

	fin.close();
	// Re-open the _username file again
	std::ofstream fout;
	fout.open((USERS_INFO_DIRECTORY + _username + ".txt").c_str());
	// Change the data and overwrite the information from the userTemp
	if (_option == 49)
		this->user.set_full_name(_info_updated);
	if (_option == 50)
		this->user.set_address(_info_updated);
	if (_option == 51)
		this->user.set_phone_number(_info_updated);
	if (_option == 52)
		this->user.set_email_address(_info_updated);
	// user.write_file(fout);

	this->write_file(fout);
	
	fout.close();
}
