#include "HandleMain.hpp"

bool has_username(std::string _username) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account account;
		AccountFileManager::read_file(fin, account);
		if (_username == account.get_username()) {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}
bool has_account(std::string _username, std::string _password) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account account;
		AccountFileManager::read_file(fin, account);
		if (account.get_username() == _username &&
			account.get_password() == _password &&
			account.get_username() != "" &&
			account.get_password() != "") {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}

AccountType get_account_type(std::string _username, std::string _password) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account account;
		AccountFileManager::read_file(fin, account);
		// TODO: account.get_username() == _username if outer, account.get_id() == "AD" if inner
		if (account.get_id() == "AD" && account.get_username() == _username && account.get_password() == _password) {
			fin.close();
			return AccountType::ADMINISTRATOR;
		}
		if (account.get_id() == "EM" && account.get_username() == _username && account.get_password() == _password) {
			fin.close();
			return AccountType::EMPLOYEE;
		}
	}
	fin.close();
	return AccountType::NONE;
}

bool is_default_password(std::string _username, std::string _password) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account account;
		AccountFileManager::read_file(fin, account);
		if (account.get_username() == _username &&
			account.get_password() == _password &&
			account.get_password() == DEFAULT_PASSWORD &&
			account.get_username() != "" &&
			account.get_password() != "") {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}
