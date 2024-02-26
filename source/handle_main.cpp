#include "handle_main.hpp"

// AccountType get_account_type(std::string _username, std::string _password) {
// 	std::ifstream fin;
// 	fin.open(ACCOUNTS_FILE.c_str());
// 	while (!fin.eof()) {
// 		Account account;
// 		AccountFileManager::read_file(fin, account);
// 		// TODO: account.get_username() == _username if outer, account.get_id() == "AD" if inner
// 		if (account.get_account_type() == AccountType::ADMINISTRATOR && account.get_username() == _username && account.get_password() == _password) {
// 			fin.close();
// 			return AccountType::ADMINISTRATOR;
// 		}
// 		if (account.get_account_type() == AccountType::EMPLOYEE && account.get_username() == _username && account.get_password() == _password) {
// 			fin.close();
// 			return AccountType::EMPLOYEE;
// 		}
// 	}
// 	fin.close();
// 	return AccountType::NONE;
// }
