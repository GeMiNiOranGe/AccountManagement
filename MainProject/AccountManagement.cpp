#include "AccountManagement.hpp"

AccountManagement::AccountManagement(const Account & _account) {
	this->account = _account;
}

const Account & AccountManagement::get_account() {
	return this->account;
}

void AccountManagement::read_file(std::ifstream & _fin) {
	std::string _id, _username, _password;
	getline(_fin, _id, ',');
	getline(_fin, _username, ',');
	getline(_fin, _password);
	this->account.set_id(_id);
	this->account.set_username(_username);
	this->account.set_password(_password);
}
void AccountManagement::write_file(std::ofstream & _fout) {
	_fout << this->account.get_id() << ',' << this->account.get_username() << ',' << this->account.get_password() << std::endl;
}


bool AccountManagement::is_success_change_pass(std::string _username, std::string _current_password, std::string _new_password, std::string _confirm_new_password) {
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
			if (!this->account.get_username().empty()) {
				if (this->account.get_username() == _username && this->account.get_password() == _current_password) {
					this->account.set_password(_new_password);
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

void AccountManagement::create_account(std::string _username) {
	// append account in file Accounts.txt
	std::ofstream fout;
	fout.open(ACCOUNTS_FILE, std::ios_base::app);

	this->account.set_id("EM");
	this->account.set_username(_username);

	this->write_file(fout);
}
void AccountManagement::delete_account(std::string _username) {
	std::ofstream fout;
	std::ifstream fin;
	const std::string old_accounts_file = ACCOUNTS_FILE;
	std::string new_accounts_file = old_accounts_file;

	// Rename Accounts.txt into AccountsTemp.txt
	new_accounts_file.insert(new_accounts_file.size() - 4, "New");
	if (rename(old_accounts_file.c_str(), new_accounts_file.c_str()) != 0) {
		std::cerr << "Error renaming file" << std::endl;
		return;
	}

	// Re-create the old Accounts.txt file without content
	fout.open(old_accounts_file);
	fin.open(new_accounts_file);
	if (!fin.is_open() || !fout.is_open()) {
		std::cerr << "Failed to open files" << std::endl;
		return;
	}

	// Write from the file is renamed (AccountsNew.txt) to Accounts.txt, and don't write the employee want to delete
	while (!fin.eof()) {
		this->read_file(fin);
		if (!this->account.get_username().empty() && this->account.get_username() != _username)
			this->write_file(fout);
	}

	fout.close();
	fin.close();
	if (remove(new_accounts_file.c_str()) != 0) {
		std::cerr << "Failed to remove file" << std::endl;
		return;
	}
}
