#include "account_storage.hpp"

void AccountStorage::for_each_account(
    const std::function<bool(const Account &)> &callback
) {
    std::ifstream fin;

    if (!is_open_file(fin, ACCOUNTS_FILE.c_str())) {
        return;
    }

    while (!fin.eof()) {
        Account account;
        AccountFileIO::read_file(fin, account);
        if (callback(account)) {
            break;
        }
    }
}

void AccountStorage::process_accounts_file(
	const std::function<void(Account &, std::ofstream &)> &processor
) {
	const std::string original_file = ACCOUNTS_FILE;
	std::string backup_file = ACCOUNTS_FILE;
	backup_file.insert(backup_file.size() - 4, "_new");

	// Rename Accounts.txt into AccountsTemp.txt
	if (rename(original_file.c_str(), backup_file.c_str()) != 0) {
		std::cerr << "Error renaming file" << std::endl;
		return;
	}

	std::ifstream fin;
	std::ofstream fout;

	// Re-create the old Accounts.txt file without content
	if (!is_open_file(fin, backup_file) || !is_open_file(fout, original_file)) {
		return;
	}

	// Write from the file is renamed (AccountsNew.txt) to Accounts.txt,
	// and don't write the employee want to delete
	while (!fin.eof()) {
		Account account;
		AccountFileIO::read_file(fin, account);
		if (!account.get_username().empty()) {
			processor(account, fout);
        }
	}

	fin.close();
	fout.close();
	remove(backup_file.c_str());
}

bool AccountStorage::has_username(const std::string &username) {
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

bool AccountStorage::has_account(const Account &account) {
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

Account AccountStorage::get_account_details(
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

void AccountStorage::create_account(const std::string &username) {
    // append account in file Accounts.txt
    std::ofstream fout(ACCOUNTS_FILE, std::ios_base::app);
    Account new_account(AccountType::EMPLOYEE, username);
    AccountFileIO::write_file(fout, new_account);
}

void AccountStorage::delete_account(const std::string &username) {
	process_accounts_file([&username](Account &account, std::ofstream &fout) {
        if (account.get_username() != username) {
			AccountFileIO::write_file(fout, account);
        }
	});
}

void AccountStorage::update_account(
	const Account &old_account,
	const Account &new_account
) {
	process_accounts_file(
		[&old_account, &new_account](Account &account, std::ofstream &fout) {
			if (account.get_username() == old_account.get_username() &&
				account.get_password() == old_account.get_password()) {
				account.set_username(new_account.get_username());
				account.set_password(new_account.get_password());
			}
			AccountFileIO::write_file(fout, account);
		}
	);
}
