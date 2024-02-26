#include "account.hpp"

Account::Account(AccountType _id, std::string _username, std::string _password) {
	this->account_type = _id;
	this->username = _username;
	this->password = _password;
}

const AccountType & Account::get_account_type() const {
	return this->account_type;
}
const std::string & Account::get_username() const {
	return this->username;
}
const std::string & Account::get_password() const {
	return this->password;
}

void Account::set_account_type(const AccountType & _id) {
	this->account_type = _id;
}
void Account::set_username(const std::string & _username) {
	this->username = _username;
}
void Account::set_password(const std::string & _password) {
	this->password = _password;
}
