#include "account_manager.hpp"

AccountManagement::AccountManagement(const Account & _account) {
	this->account = _account;
}

const Account & AccountManagement::get_account() const {
	return this->account;
}
void AccountManagement::set_account(const Account &_account) {
	this->account = _account;
}

bool AccountManagement::has_username(const std::string &_username) {
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
bool AccountManagement::has_account(const Account &_account) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account account;
		AccountFileManager::read_file(fin, account);
		if (account.get_username() == _account.get_username() &&
			account.get_password() == _account.get_password() &&
			account.get_username() != "" &&
			account.get_password() != "") {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}

void AccountManagement::create_account(const std::string &_username) {
	// append account in file Accounts.txt
	std::ofstream fout;
	fout.open(ACCOUNTS_FILE, std::ios_base::app);

	this->account.set_id("EM");
	this->account.set_username(_username);
	this->account.set_password(DEFAULT_PASSWORD);

	AccountFileManager::write_file(this->account, fout);
}
void AccountManagement::delete_account(const std::string &_username) {
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
		AccountFileManager::read_file(fin, this->account);
		if (!this->account.get_username().empty() && this->account.get_username() != _username)
			AccountFileManager::write_file(this->account, fout);
	}

	fout.close();
	fin.close();
	if (remove(new_accounts_file.c_str()) != 0) {
		std::cerr << "Failed to remove file" << std::endl;
		return;
	}
}
void AccountManagement::update_account(const Account &_old_account, const Account &_new_account) {
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

	// Write from the file is renamed (AccountsNew.txt) to Accounts.txt, and update password the account want to update
	while (!fin.eof()) {
		AccountFileManager::read_file(fin, this->account);
		if (!this->account.get_username().empty()) {
			if (this->account.get_username() == _old_account.get_username() &&
				this->account.get_password() == _old_account.get_password()) {
				this->account.set_username(_new_account.get_username());
				this->account.set_password(_new_account.get_password());
			}
			AccountFileManager::write_file(this->account, fout);
		}
	}

	fout.close();
	fin.close();
	if (remove(new_accounts_file.c_str()) != 0) {
		std::cerr << "Failed to remove file" << std::endl;
		return;
	}
}
