#include "Account.hpp"

Account::Account(std::string _id, std::string _username, std::string _password) {
	this->id = _id;
	this->username = _username;
	this->password = _password;
}

const std::string & Account::get_id() const {
	return this->id;
}
const std::string & Account::get_username() const {
	return this->username;
}
const std::string & Account::get_password() const {
	return this->password;
}

void Account::set_id(const std::string & _id) {
	this->id = _id;
}
void Account::set_username(const std::string & _username) {
	this->username = _username;
}
void Account::set_password(const std::string & _password) {
	this->password = _password;
}

void Account::read_file(std::ifstream & _fin) {
	std::string _id, _username, _password;
	getline(_fin, _id, ',');
	getline(_fin, _username, ',');
	getline(_fin, _password);
	this->id = _id;
	this->username = _username;
	this->password = _password;
}
void Account::write_file(std::ofstream & _fout) {
	_fout << this->id << ',' << this->username << ',' << this->password << std::endl;
}

bool Account::is_success_change_pass(std::string _username, std::string _current_password, std::string _new_password, std::string _confirm_new_password) {
	bool is_successful = false;
	if (_current_password != _new_password && _new_password == _confirm_new_password) {
		const std::string accounts = ACCOUNTS_FILE;
		std::string accounts_temp = accounts;

		// Rename Accounts.txt into AccountsTemp.txt
		accounts_temp.insert(accounts_temp.size() - 4, "Temp");
		if (rename(accounts.c_str(), accounts_temp.c_str()) != 0) {
			std::cerr << "Error renaming file" << std::endl;
			return false;
		}

		// Automatically create a new Accounts.txt
		std::ofstream fout(accounts);
		std::ifstream fin;
		// And open the file is renamed (AccountsTemp.txt)
		fin.open(accounts_temp.c_str());

		if (!fin.is_open() || !fout.is_open()) {
			std::cerr << "Failed to open files" << std::endl;
			return false;
		}

		// Write from the file is renamed (AccountsTemp.txt) to Accounts.txt
		// And update password the account want to update
		while (!fin.eof()) {
			this->read_file(fin);
			if (!this->username.empty()) {
				if (this->username == _username && this->password == _current_password) {
					this->password = _new_password;
					this->write_file(fout);
					is_successful = true;
				}
				else
					this->write_file(fout);
			}
		}

		fout.close();
		fin.close();
		if (remove(accounts_temp.c_str()) != 0) {
			std::cerr << "Failed to remove file" << std::endl;
			return false;
		}
	}
	return is_successful;
}
