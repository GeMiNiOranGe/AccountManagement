#include "account_manager.hpp"

void AccountManager::for_each_account(
    const std::function<bool(const Account &)> &callback
) {
    std::ifstream fin;

    if (!is_open_file(fin, ACCOUNTS_FILE.c_str())) {
        return;
    }

    while (!fin.eof()) {
        Account acc;
        AccountFileManager::read_file(fin, acc);
        if (callback(acc)) {
            break;
        }
    }
}

bool AccountManager::has_username(const std::string &username) {
    bool found = false;

    for_each_account(
        [&](const Account &item) {
            if (item.get_username() == username) {
                found = true;
                return true;
            }
            return false;
        }
    );

    return found;
}

bool AccountManager::has_account(const Account &account) {
    bool found = false;

    for_each_account(
        [&](const Account &item) {
            if (item.get_username() == account.get_username() &&
				item.get_password() == account.get_password() &&
				item.get_username() != "" &&
				item.get_password() != "") {
                found = true;
                return true;
            }
            return false;
        }
    );

    return found;
}

Account AccountManager::get_account_details(
    const std::string &username,
    const std::string &password
) {
    Account result;

    for_each_account(
        [&](const Account &item) {
            if (item.get_username() == username &&
				item.get_password() == password) {
                result = item;
                return true;
            }
            return false;
        }
    );

    return result;
}

void AccountManager::create_account(const std::string &_username) {
    // append account in file Accounts.txt
    std::ofstream fout(ACCOUNTS_FILE, std::ios_base::app);
    Account new_account(AccountType::EMPLOYEE, _username);
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
