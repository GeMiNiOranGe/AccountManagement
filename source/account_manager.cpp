#include "account_manager.hpp"

bool AccountManager::has_username(const std::string &_username) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account current_account;
		AccountFileManager::read_file(fin, current_account);
		if (current_account.get_username() == _username) {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}
bool AccountManager::has_account(const Account &_account) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		Account current_account;
		AccountFileManager::read_file(fin, current_account);
		if (current_account.get_username() == _account.get_username() &&
			current_account.get_password() == _account.get_password() &&
			current_account.get_username() != "" &&
			current_account.get_password() != "") {
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}

Account AccountManager::get_account_details(const std::string &_username, const std::string &_password) {
	std::ifstream fin;

	fin.open(ACCOUNTS_FILE.c_str());
	if (!fin.is_open()) {
		std::cerr << "Failed to open files" << std::endl;
		return Account();
	}
	
	while (!fin.eof()) {
		Account current_account;
		AccountFileManager::read_file(fin, current_account);
		if (current_account.get_username() == _username &&
			current_account.get_password() == _password) {
			fin.close();
			return current_account;
		}
	}

	fin.close();
	return Account();
}

void AccountManager::create_account(const std::string &_username) {
	// append account in file Accounts.txt
	std::ofstream fout;
	Account new_account(AccountType::EMPLOYEE, _username);

	fout.open(ACCOUNTS_FILE, std::ios_base::app);
	AccountFileManager::write_file(fout, new_account);
}
void AccountManager::delete_account(const std::string &_username) {
	std::ofstream fout;
	std::ifstream fin;
	const std::string old_accounts_file = ACCOUNTS_FILE;
	std::string new_accounts_file = old_accounts_file;

	// Rename Accounts.txt into AccountsTemp.txt
	new_accounts_file.insert(new_accounts_file.size() - 4, "_new");
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
		Account current_account;
		AccountFileManager::read_file(fin, current_account);
		if (!current_account.get_username().empty() && current_account.get_username() != _username)
			AccountFileManager::write_file(fout, current_account);
	}

	fout.close();
	fin.close();
	if (remove(new_accounts_file.c_str()) != 0) {
		std::cerr << "Failed to remove file" << std::endl;
		return;
	}
}
void AccountManager::update_account(const Account &_old_account, const Account &_new_account) {
	std::ofstream fout;
	std::ifstream fin;
	const std::string old_accounts_file = ACCOUNTS_FILE;
	std::string new_accounts_file = old_accounts_file;

	// Rename Accounts.txt into AccountsTemp.txt
	new_accounts_file.insert(new_accounts_file.size() - 4, "_new");
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
		Account current_account;
		AccountFileManager::read_file(fin, current_account);
		if (!current_account.get_username().empty()) {
			if (current_account.get_username() == _old_account.get_username() &&
				current_account.get_password() == _old_account.get_password()) {
				current_account.set_username(_new_account.get_username());
				current_account.set_password(_new_account.get_password());
			}
			AccountFileManager::write_file(fout, current_account);
		}
	}

	fout.close();
	fin.close();
	if (remove(new_accounts_file.c_str()) != 0) {
		std::cerr << "Failed to remove file" << std::endl;
		return;
	}
}
