#include "HandleMain.hpp"

//std::ofstream create_file(std::string _username) {
//	std::string path = USERS_DIRECTORY + _username + ".txt";
//	std::ofstream fout;
//	fout.open(path);
//	return fout;
//}
// std::ifstream open_file(std::string _username) {
// 	std::string path = USERS_DIRECTORY + _username + ".txt";
// 	std::ifstream fin;
// 	fin.open(path);
// 	return fin;
// }

bool has_username(std::string _username) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		AccountManagement account;
		account.read_file(fin);
		if (_username == account.get_account().get_username()) {
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
		AccountManagement account;
		account.read_file(fin);
		if (account.get_account().get_username() == _username &&
			account.get_account().get_password() == _password &&
			account.get_account().get_username() != "" &&
			account.get_account().get_password() != "") {
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
		AccountManagement account;
		account.read_file(fin);
		if (account.get_account().get_id() == "AD" && account.get_account().get_username() == _username && account.get_account().get_password() == _password) {
			fin.close();
			return AccountType::ADMINISTRATOR;
		}
		if (account.get_account().get_id() == "EM" && account.get_account().get_username() == _username && account.get_account().get_password() == _password) {
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
		AccountManagement account;
		account.read_file(fin);
		if (account.get_account().get_username() == _username &&
			account.get_account().get_password() == _password &&
			account.get_account().get_password() == DEFAULT_PASSWORD &&
			account.get_account().get_username() != "" &&
			account.get_account().get_password() != "") {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}
