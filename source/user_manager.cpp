#include "user_manager.hpp"

UserManagement::UserManagement(const User &_user) {
	this->user = _user;
}

const User &UserManagement::get_user() const {
    return this->user;
}

void UserManagement::set_user(const User &_user) {
	this->user = _user;
}

void UserManagement::create_user(const std::string &_username, const User &_user_information) {
	const std::string PATH = USERS_DIRECTORY + _username + ".txt";
	std::ofstream fout;
	fout.open(PATH);
	UserFileManager::write_file(_user_information, fout);
	fout.close();
}
void UserManagement::delete_user(const std::string &_username) {
	const std::string COMMAND = "del " + USERS_DIRECTORY + _username + ".txt";
	// TODO: use remove funcion
	system(COMMAND.c_str());
}
void UserManagement::update_user(const std::string &_username, std::string _info_updated, char _option) {
	// Load infomation from _username file
	std::ifstream fin = UserFileManager::open_file(_username);
	UserFileManager::read_file(fin, this->user);
	fin.close();

	// Re-open the _username file again
	std::ofstream fout;
	fout.open((USERS_DIRECTORY + _username + ".txt").c_str());

	// Change the data and overwrite the information from the userTemp
	if (_option == 49)
		this->user.set_full_name(_info_updated);
	if (_option == 50)
		this->user.set_address(_info_updated);
	if (_option == 51)
		this->user.set_phone_number(_info_updated);
	if (_option == 52)
		this->user.set_email_address(_info_updated);
	
	UserFileManager::write_file(this->user, fout);
	fout.close();
}
User UserManagement::read_user(const std::string &_username) {
	std::ifstream fin = UserFileManager::open_file(_username);
	UserFileManager::read_file(fin, this->user);
	fin.close();
	return this->user;
}
