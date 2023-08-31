#include "Employee.h"

Employee::Employee(
	std::string _username, std::string _password, std::string _id,
	std::string _full_name, std::string _address,
	std::string _phone_number, std::string _email_address
) : User(_username, _password, _id, _full_name, _address, _phone_number, _email_address) {
}

bool Employee::is_success_change_pass(std::string _username, std::string _current_password, std::string _new_password, std::string _confirm_new_password) {
	bool is_successful = false;
	if (_new_password == _confirm_new_password) {
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
			io::File::read_account_from(fin, *this);
			if (!User::get_username().empty()) {
				if (User::get_username() == _username && User::get_password() == _current_password && User::get_password() != _new_password) {
					User::set_password(_new_password);
					io::File::write_account_from(*this, fout);
					is_successful = true;
				}
				else
					io::File::write_account_from(*this, fout);
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
