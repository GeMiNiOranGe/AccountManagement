#include "account.hpp"

Account::Account(std::string _id, std::string _username, std::string _password) {
	this->id = _id;
	this->username = _username;
	this->password = _password;
}

const std::string & Account::get_id() const {
	return this->id;
}
const std::string & Account::get_username() const {
	return this->username;
}
const std::string & Account::get_password() const {
	return this->password;
}

void Account::set_id(const std::string & _id) {
	this->id = _id;
}
void Account::set_username(const std::string & _username) {
	this->username = _username;
}
void Account::set_password(const std::string & _password) {
	this->password = _password;
}
