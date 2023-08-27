#include "HandleMain.h"

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

void delete_account(std::string _source_file, std::string _username) {
	User _user;
	// Rename Employees.txt into EmployeesTemp.txt
	std::string accounts_file_temp = _source_file;
	rename(_source_file.c_str(), accounts_file_temp.insert(accounts_file_temp.size() - 4, "Temp").c_str());
	// Create a new Employees.txt and open the file is renamed (EmployeesTemp.txt)
	std::ofstream fout(_source_file);
	std::ifstream fin;
	fin.open(accounts_file_temp.c_str());
	// Write from the file is renamed (EmployeesTemp.txt) to Employees.txt
	// and don't write the employee want to delete
	while (!fin.eof()) {
		io::File::read_account_from(fin, _user);
		if (_user.get_username() != _username && _user.get_username() != "")
			io::File::write_account_from(_user, fout);
	}
	fout.close();
	fin.close();
	// Delete the file is renamed (EmployeesTemp.txt)
	system(accounts_file_temp.insert(0, "del ").c_str());
}

void show_account_info(std::string _username) {
	User _user;
	std::ifstream fin = open_file(_username);
	io::File::read_info_from(fin, _user);
	console::write_info(_user);
	fin.close();
}

bool has_username(std::string _username) {
	std::ifstream fin;
	fin.open(ACCOUNTS_FILE.c_str());
	while (!fin.eof()) {
		User _user;
		io::File::read_account_from(fin, _user);
		if (_username == _user.get_username()) {
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
		User _user;
		io::File::read_account_from(fin, _user);
		if (_username == _user.get_username() && _password == _user.get_password() && _user.get_username() != "" && _user.get_password() != "") {
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
		User _user;
		io::File::read_account_from(fin, _user);
		if (_user.get_id() == "AD" && _user.get_username() == _username && _user.get_password() == _password) {
			fin.close();
			return AccountType::ADMINISTRATOR;
		}
		if (_user.get_id() == "EM" && _user.get_username() == _username && _user.get_password() == _password) {
			fin.close();
			return AccountType::EMPLOYEE;
		}
	}
	fin.close();
	return AccountType::NONE;
}
