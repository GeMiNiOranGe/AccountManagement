#include "account.hpp"

Account::Account(AccountRole _role, std::string _username, std::string _password) {
	this->role = _role;
	this->username = _username;
	this->password = _password;
}

const AccountRole & Account::get_role() const {
	return this->role;
}
const std::string & Account::get_username() const {
	return this->username;
}
const std::string & Account::get_password() const {
	return this->password;
}

void Account::set_role(const AccountRole & _role) {
	this->role = _role;
}
void Account::set_username(const std::string & _username) {
	this->username = _username;
}
void Account::set_password(const std::string & _password) {
	this->password = _password;
}
