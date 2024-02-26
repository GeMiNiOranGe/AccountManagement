#include "user_manager.hpp"

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
	User user;

	// Load infomation from _username file
	std::ifstream fin = UserFileManager::open_file(_username);
	UserFileManager::read_file(fin, user);
	fin.close();

	// Re-open the _username file again
	std::ofstream fout;
	fout.open((USERS_DIRECTORY + _username + ".txt").c_str());

	// Change the data and overwrite the information from the userTemp
	if (_option == 49)
		user.set_full_name(_info_updated);
	if (_option == 50)
		user.set_address(_info_updated);
	if (_option == 51)
		user.set_phone_number(_info_updated);
	if (_option == 52)
		user.set_email_address(_info_updated);
	
	UserFileManager::write_file(fout, user);
	fout.close();
}
User UserManager::read_user(const std::string &_username) {
	User user;
	std::ifstream fin = UserFileManager::open_file(_username);
	UserFileManager::read_file(fin, user);
	fin.close();
	return user;
}
