#include "Employee.h"

Employee::Employee(
	std::string _username, std::string _password, std::string _id,
	std::string _full_name, std::string _address,
	std::string _phone_number, std::string _email_address
) : User(_username, _password, _id, _full_name, _address, _phone_number, _email_address) {
}

bool Employee::isSuccessChangePass(std::string strUsername, std::string strCurrentPass, std::string strNewPass, std::string strConfirmNewPass) {
	std::ifstream fileIn;
	fileIn.open(ACCOUNTS_FILE.c_str());
	while (!fileIn.eof()) {
		io::File::read_account_from(fileIn, *this);
		if (User::get_username() == strUsername && User::get_password() == strCurrentPass && strNewPass == strConfirmNewPass) {
			User::set_password(strNewPass);
			fileIn.close();
			delete_account(ACCOUNTS_FILE, strUsername);
			std::ofstream fileOut;
			fileOut.open(ACCOUNTS_FILE.c_str(), std::ios_base::app);
			io::File::write_account_from(*this, fileOut);
			fileOut.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
