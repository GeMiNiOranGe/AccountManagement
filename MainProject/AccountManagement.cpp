#include "AccountManagement.hpp"

AccountManagement::AccountManagement(const Account & _account) {
	this->account = _account;
}

const Account & AccountManagement::get_account() const {
	return this->account;
}
void AccountManagement::set_account(const Account &_account) {
	this->account = _account;
}

// bool AccountManagement::is_success_change_pass(std::string _username, std::string _current_password, std::string _new_password, std::string _confirm_new_password) {
// 	bool is_successful = false;
// 	if (_current_password != _new_password && _new_password == _confirm_new_password) {
// 		std::ofstream fout;
// 		std::ifstream fin;
// 		const std::string old_accounts_file = ACCOUNTS_FILE;
// 		std::string new_accounts_file = old_accounts_file;

// 		// Rename Accounts.txt into AccountsTemp.txt
// 		new_accounts_file.insert(new_accounts_file.size() - 4, "New");
// 		if (rename(old_accounts_file.c_str(), new_accounts_file.c_str()) != 0) {
// 			std::cerr << "Error renaming file" << std::endl;
// 			return false;
// 		}

// 		// Re-create the old Accounts.txt file without content
// 		fout.open(old_accounts_file);
// 		fin.open(new_accounts_file);
// 		if (!fin.is_open() || !fout.is_open()) {
// 			std::cerr << "Failed to open files" << std::endl;
// 			return false;
// 		}

// 		// Write from the file is renamed (AccountsNew.txt) to Accounts.txt, and update password the account want to update
// 		while (!fin.eof()) {
// 			AccountFileManager::read_file(fin, this->account);
// 			if (!this->account.get_username().empty()) {
// 				if (this->account.get_username() == _username && this->account.get_password() == _current_password) {
// 					this->account.set_password(_new_password);
// 					is_successful = true;
// 				}
// 				AccountFileManager::write_file(this->account, fout);
// 			}
// 		}

// 		fout.close();
// 		fin.close();
// 		if (remove(new_accounts_file.c_str()) != 0) {
// 			std::cerr << "Failed to remove file" << std::endl;
// 			return false;
// 		}
// 	}
// 	return is_successful;
// }

void AccountManagement::create_account(std::string _username) {
	// append account in file Accounts.txt
	std::ofstream fout;
	fout.open(ACCOUNTS_FILE, std::ios_base::app);

	this->account.set_id("EM");
	this->account.set_username(_username);

	AccountFileManager::write_file(this->account, fout);
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
void AccountManagement::update_account(Account _old_account, Account _new_account) {
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
			if (this->account.get_username() == _old_account.get_username() && this->account.get_password() == _old_account.get_password()) {
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
