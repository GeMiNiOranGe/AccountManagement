#include "Administrator.hpp"

Administrator::Administrator(
	/*std::string _username, std::string _password, */std::string _id,
	std::string _full_name, std::string _address,
	std::string _phone_number, std::string _email_address
) : User(/*_username, _password, */_id, _full_name, _address, _phone_number, _email_address) {
}

void Administrator::add_employee(std::string _username) {
	// Update file Employees.txt
	std::ofstream account_list;
	account_list.open(ACCOUNTS_FILE, std::ios_base::app);
	account_list << "EM," << _username << ',' << DEFAULT_PASSWORD << std::endl;
	// Create a new file and add information to the newly created file
	std::ofstream fout = create_file(_username);
	console::read_info(*this);
	io::File::write_info_from(*this, fout);
	fout.close();
}
void Administrator::erase_employee(std::string _username) {
	delete_account(_username);
	delete_file(_username);
}
void Administrator::update_info_employee(std::string _username, std::string _info_updated, char _option) {
	// Load infomation from _username file
	std::ifstream fin = open_file(_username);
	io::File::read_info_from(fin, *this);
	fin.close();
	// Re-open the _username file again
	std::ofstream fout;
	fout.open((USERS_INFO_FOLDER + _username + ".txt").c_str());
	// Change the data and overwrite the information from the userTemp
	if (_option == 49)
		User::set_full_name(_info_updated);
	if (_option == 50)
		User::set_address(_info_updated);
	if (_option == 51)
		User::set_phone_number(_info_updated);
	if (_option == 52)
		User::set_email_address(_info_updated);
	io::File::write_info_from(*this, fout);
	fout.close();
}
