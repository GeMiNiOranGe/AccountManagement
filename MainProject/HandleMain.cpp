#include "HandleMain.hpp"

std::ofstream create_file(std::string _username) {
	std::string path = USERS_INFO_FOLDER + _username + ".txt";
	std::ofstream new_file(path);
	return new_file;
}
std::ifstream open_file(std::string _username) {
	std::string path = USERS_INFO_FOLDER + _username + ".txt";
	std::ifstream fin;
	fin.open(path);
	return fin;
}
void delete_file(std::string _username) {
	std::string command = "del " + USERS_INFO_FOLDER + _username + ".txt";
	system(command.c_str());
}

void delete_account(std::string _username) {
	const std::string accounts = ACCOUNTS_FILE;
	std::string accounts_temp = accounts;
	Account account;

	// Rename Accounts.txt into AccountsTemp.txt
	accounts_temp.insert(accounts_temp.size() - 4, "Temp");
	if (rename(accounts.c_str(), accounts_temp.c_str()) != 0) {
		std::cerr << "Error renaming file" << std::endl;
		return;
	}

	// Automatically create a new Accounts.txt
	std::ofstream fout(accounts);
	std::ifstream fin;
	// And open the file is renamed (AccountsTemp.txt)
	fin.open(accounts_temp.c_str());

	if (!fin.is_open() || !fout.is_open()) {
		std::cerr << "Failed to open files" << std::endl;
		return;
	}

	// Write from the file is renamed (AccountsTemp.txt) to Accounts.txt
	// And don't write the employee want to delete
	while (!fin.eof()) {
		io::File::read_account_from(fin, account);
		if (!account.get_username().empty() && account.get_username() != _username)
			io::File::write_account_from(account, fout);
	}
	fout.close();
	fin.close();
	if (remove(accounts_temp.c_str()) != 0) {
		std::cerr << "Failed to remove file" << std::endl;
		return;
	}
}

void show_account_info(std::string _username) {
	User user;
	std::ifstream fin = open_file(_username);
	io::File::read_info_from(fin, user);
	console::write_info(user);
	fin.close();
}

bool has_username(std::string _username) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account account;
		io::File::read_account_from(fin, account);
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
		io::File::read_account_from(fin, account);
		if (_username == account.get_username() && _password == account.get_password() && account.get_username() != "" && account.get_password() != "") {
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
		io::File::read_account_from(fin, account);
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
		io::File::read_account_from(fin, account);
		if (_username == account.get_username() && _password == account.get_password() && account.get_password() == DEFAULT_PASSWORD && account.get_username() != "" && account.get_password() != "") {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}
