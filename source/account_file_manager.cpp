#include "account_file_manager.hpp"

void AccountFileManager::read_file(std::ifstream &_fin, Account &_account) {
	std::string _id, _username, _password;
	getline(_fin, _id, ',');
	getline(_fin, _username, ',');
	getline(_fin, _password);
	_account.set_id(_id);
	_account.set_username(_username);
	_account.set_password(_password);
}
void AccountFileManager::write_file(const Account &_account, std::ofstream &_fout) {
	_fout << _account.get_id() << ','
		<< _account.get_username() << ','
		<< _account.get_password() << std::endl;
}
