#include "user_manager.hpp"

UserManager::UserManager(const User &_user) {
	this->user = _user;
}

const User &UserManager::get_user() const {
    return this->user;
}

void UserManager::set_user(const User &_user) {
	this->user = _user;
}

void UserManager::create_user(const std::string &_username, const User &_user_information) {
	const std::string PATH = USERS_DIRECTORY + _username + ".txt";
	std::ofstream fout;
	fout.open(PATH);
	UserFileManager::write_file(fout, _user_information);
	fout.close();
}
void UserManager::delete_user(const std::string &_username) {
	const std::string COMMAND = "del " + USERS_DIRECTORY + _username + ".txt";
	// TODO: use remove funcion
	system(COMMAND.c_str());
}
// TODO: update from new_user to old_user
void UserManager::update_user(const std::string &_username, std::string _info_updated, char _option) {
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
	
	UserFileManager::write_file(fout, this->user);
	fout.close();
}
User UserManager::read_user(const std::string &_username) {
	std::ifstream fin = UserFileManager::open_file(_username);
	UserFileManager::read_file(fin, this->user);
	fin.close();
	return this->user;
}
