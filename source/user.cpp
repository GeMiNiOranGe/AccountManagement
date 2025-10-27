#include "user.hpp"

User::User(std::string _username, std::string _full_name, std::string _address, std::string _phone_number, std::string _email_address) {
	this->username = _username;
	this->full_name = _full_name;
	this->address = _address;
	this->phone_number = _phone_number;
	this->email_address = _email_address;
}
User::User(const User & _user) {
	this->username = _user.username;
	this->full_name = _user.full_name;
	this->address = _user.address;
	this->phone_number = _user.phone_number;
	this->email_address = _user.email_address;
}
User::~User() {
}

const std::string & User::get_username() const {
	return this->username;
}
const std::string & User::get_full_name() const {
	return this->full_name;
}
const std::string & User::get_address() const {
	return this->address;
}
const std::string & User::get_phone_number() const {
	return this->phone_number;
}
const std::string & User::get_email_address() const {
	return this->email_address;
}

void User::set_username(const std::string & _username) {
	this->username = _username;
}
void User::set_full_name(const std::string & _full_name) {
	this->full_name = _full_name;
}
void User::set_address(const std::string & _address) {
	this->address = _address;
}
void User::set_phone_number(const std::string & _phone_number) {
	this->phone_number = _phone_number;
}
void User::set_email_address(const std::string & _email_address) {
	this->email_address = _email_address;
}
